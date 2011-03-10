#include <rsx/mm.h>
#include <rsx/gcm_sys.h>
#include <ppu-asm.h>

gcmContextData* rsxInit(const u32 cmdSize,const u32 ioSize,const void *ioAddress)
{
	s32 ret = -1;
	u32 context = 0;

	ret = gcmInitBody(&context,cmdSize,ioSize,ioAddress);
	if(ret==0) {
		rsxHeapInit(cmdSize,ioSize);
		return (gcmContextData*)((u64)context);
	}
	return NULL;
}

void rsxSetupContextData(gcmContextData *context,const u32 *addr,const u32 size,gcmContextCallback cb)
{
	u32 alignedSize = size&~0x3;

	context->begin = __get_addr32(addr);
	context->current = __get_addr32(addr);
	context->end = __get_addr32(addr + alignedSize - 4);
	context->callback = __get_addr32(__get_opd32(cb));
}
