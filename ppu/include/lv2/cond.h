#ifndef __LV2_COND_H__
#define __LV2_COND_H__

#include <ppu-types.h>
#include <lv2/mutex.h>
#include <lv2/thread.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct sys_lwcond
{
	sys_lwmutex_t *lwmutex;
	u32 lwcond_queue;
} sys_lwcond_t;

typedef struct sys_lwcond_attr
{
	char name[8];
} sys_lwcond_attr_t;

s32 sysLwCondCreate(sys_lwcond_t *lwcond,sys_lwmutex_t *lwmutex,sys_lwcond_attr_t *attr);
s32 sysLwCondDestroy(sys_lwcond_t *lwcond);
s32 sysLwCondWait(sys_lwcond_t *lwcond,u64 timeout_usec);
s32 sysLwCondSignal(sys_lwcond_t *lwcond);
s32 sysLwCondSignalTo(sys_lwcond_t *lwcond,sys_ppu_thread_t thr);
s32 sysLwCondSignalAll(sys_lwcond_t *lwcond);

#ifdef __cplusplus
	}
#endif

#endif
