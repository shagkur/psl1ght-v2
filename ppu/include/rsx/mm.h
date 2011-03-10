#ifndef __RSX_MM_H__
#define __RSX_MM_H__

#include <ppu-types.h>

#ifdef __cplusplus
extern "C" {
#endif

s32 rsxHeapInit();

void* rsxMalloc(u32 size);
void* rsxMemalign(u32 alignment,u32 size);

void rsxFree(void *ptr);

#ifdef __cplusplus
	}
#endif

#endif
