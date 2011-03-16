/*! \file cond.h
 \brief Condition variables management.
*/

#ifndef __SYS_COND_H__
#define __SYS_COND_H__

#include <mutex.h>
#include <lv2/cond.h>

#define SYS_COND_ATTR_PSHARED			0x0200

#ifdef __cplusplus
	extern "C" {
#endif

typedef u32 sys_cont_t;

typedef struct sys_cond_attr
{
	u32 attr_pshared;
	s32 flags;
	u64 key;
	char name[8];
} sys_cond_attr_t;

LV2_SYSCALL sysCondCreate(sys_cond_t *cond,sys_mutex_t mutex,const sys_cond_attr_t *attr)
{
	return lv2syscall3(105,(u64)cond,mutex,(u64)attr);
}

LV2_SYSCALL sysCondDestroy(sys_cond_t cond)
{
	return lv2syscall1(106,cond);
}

LV2_SYSCALL sysCondWait(sys_cond_t cond,u64 timeout_usec)
{
	return lv2syscall2(107,cond,timeout_usec);
}

LV2_SYSCALL sysCondSignal(sys_cond_t cond)
{
	return lv2syscall1(108,cond);
}

LV2_SYSCALL sysCondBroadcast(sys_cond_t cond)
{
	return lv2syscall1(109,cond)
}

#ifdef __cplusplus
	}
#endif

#endif
