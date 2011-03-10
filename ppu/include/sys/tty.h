#ifndef __SYS_TTY_H__
#define __SYS_TTY_H__

#include <ppu-lv2.h>

#ifdef __cplusplus
	extern "C" {
#endif

LV2_SYSCALL sysTtyWrite(s32 channel,const void *ptr,u32 len,u32 *written)
{
	return lv2syscall4(403,channel,(u64)ptr,len,(u64)written);
}

LV2_SYSCALL sysTtyRead(s32 channel,void *ptr,u32 len,u32 *read)
{
	return lv2syscall4(402,channel,(u64)ptr,len,(u64)read);
}

#ifdef __cplusplus
	}
#endif

#endif
