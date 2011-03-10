#ifndef __LV2_MUTEX_H__
#define __LV2_MUTEX_H__

#include <ppu-types.h>

#define SYS_LWMUTEX_ATTR_PROTOCOL		0x0002
#define SYS_LWMUTEX_ATTR_RECURSIVE		0x0010

#ifdef __cplusplus
extern "C" {
#endif

typedef struct sys_lwmutex
{
	u64 lock_var;
	u32 attribute;
	u32 recursive_count;
	u32 sleep_queue;
	u32 _pad;
} sys_lwmutex_t;

typedef struct sys_lwmutex_attr
{
	u32 attr_protocol;
	u32 attr_recursive;
	char name[8];
} sys_lwmutex_attr_t;

s32 sysLwMutexCreate(sys_lwmutex_t *mutex,const sys_lwmutex_attr_t *attr);
s32 sysLwMutexDestroy(sys_lwmutex_t *mutex);
s32 sysLwMutexLock(sys_lwmutex_t *mutex,u64 timeout);
s32 sysLwMutexTryLock(sys_lwmutex_t *mutex);
s32 sysLwMutexUnlock(sys_lwmutex_t *mutex);

#ifdef __cplusplus
	}
#endif

#endif
