#ifndef __SYS_MUTEX_H__
#define __SYS_MUTEX_H__

#include <ppu-lv2.h>
#include <lv2/mutex.h>

#define SYS_MUTEX_PROTOCOL_FIFO				1
#define SYS_MUTEX_PROTOCOL_PRIO				2
#define SYS_MUTEX_PROTOCOL_PRIO_INHERIT		3

#define SYS_MUTEX_ATTR_PROTOCOL			0x0002
#define SYS_MUTEX_ATTR_RECURSIVE		0x0010
#define SYS_MUTEX_ATTR_NOT_RECURSIVE	0x0020
#define SYS_MUTEX_ATTR_PSHARED			0x0200
#define SYS_MUTEX_ATTR_ADAPTIVE			0x1000
#define SYS_MUTEX_ATTR_NOT_ADAPTIVE		0x2000

#ifdef __cplusplus
	extern "C" {
#endif

typedef s32 sys_mutex_t;

typedef struct sys_mutex_attr
{
	u32 attr_protocol;
	u32 attr_recursive;
	u32 attr_pshared;
	u32 attr_adaptive;
	u64 key;
	s32 flags;
	u32 _pad;
	char name[8];
} sys_mutex_attr_t;

LV2_SYSCALL sysMutexCreate(sys_mutex_t *mutex,const sys_mutex_attr_t *attr)
{
	return lv2syscall2(100,(u64)mutex,(u64)attr);
}

LV2_SYSCALL sysMutexDestroy(sys_mutex_t mutex)
{
	return lv2syscall1(101,mutex);
}

LV2_SYSCALL sysMutexLock(sys_mutex_t mutex,u64 timeout_usec)
{
	return lv2syscall2(102,mutex,timeout_usec);
}

LV2_SYSCALL sysMutexTryLock(sys_mutex_t mutex)
{
	return lv2syscall1(103,mutex);
}

LV2_SYSCALL sysMutexUnlock(sys_mutex_t mutex)
{
	return lv2syscall1(104,mutex);
}

#ifdef __cplusplus
	}
#endif

#endif
