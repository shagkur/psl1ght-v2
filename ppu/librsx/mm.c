#include <stdlib.h>

#include <gcm_sys.h>
#include <sys/heap.h>

static gcmConfiguration __rsx_config;

static heap_cntrl __rsx_heap;
static u64 __rsxheap_initialized = 0;

s64 rsxHeapInit()
{
	if(!__rsxheap_initialized) {
		void *start;
		u32 size;

		gcmGetConfiguration(&__rsx_config);

		start = (void*)((u64)__rsx_config.localAddress);
		size =  __rsx_config.localSize;

		heapInit(&__rsx_heap,start,size);
		__rsxheap_initialized = 1;
	}

	return 1;
}

void* rsxMemalign(u32 alignment,u32 size)
{
	if(!__rsxheap_initialized) return NULL;
	return heapAllocateAligned(&__rsx_heap,size,alignment);
}

void* rsxMalloc(u32 size)
{
	if(!__rsxheap_initialized) return NULL;
	return heapAllocate(&__rsx_heap,size);
}

void rsxFree(void *ptr)
{
	if(!__rsxheap_initialized) return;
	heapFree(&__rsx_heap,ptr);
}
