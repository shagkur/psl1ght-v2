#ifndef __LV2_THREAD_H__
#define __LV2_THREAD_H__

#include <ppu-types.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef u64 sys_ppu_thread_t;

void sysThreadExit(u64 ret_val);
s32 sysThreadGetId(sys_ppu_thread_t *threadid);

#ifdef __cplusplus
	}
#endif

#endif
