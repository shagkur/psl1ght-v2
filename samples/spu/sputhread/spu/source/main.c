#include <spu_intrinsics.h>
#include <spu_mfcio.h>

#include <sys/spu_thread.h>

#define TAG 1

/* wait for dma transfer to be finished */
static void wait_for_completion(void) {
	mfc_write_tag_mask(1<<TAG);
	spu_mfcstat(MFC_TAG_UPDATE_ALL);
}

static void send_response(uint64_t sync_ea, uint64_t response_ea, uint32_t x) {
	/* sync variable (memory alignment is required by dma) */
	static uint32_t sync __attribute__((aligned(128))) = 1;
	/* sync variable (memory alignment is required by dma) */
	static uint32_t response __attribute__((aligned(128)));
	response = x;
	/* send response to ppu variable */
	mfc_put(&response, response_ea, 4, TAG, 0, 0);
	/* send sync to ppu variable with fence (this ensures sync is written AFTER response) */
	mfc_putf(&sync, sync_ea, 4, TAG, 0, 0);
}

int main(uint64_t sync_ea, uint64_t response_ea, uint64_t arg3, uint64_t arg4) {
	/* get input value from ppu via signal notification register 1 (blocking read) */
	uint32_t x = spu_read_signal1();

	/* return the value multiplied by 3 to response variable with sync via dma */
	send_response(sync_ea, response_ea, x*3);
	wait_for_completion();

	/* properly exit the thread */
	spu_thread_exit(0);
	return 0;
}

