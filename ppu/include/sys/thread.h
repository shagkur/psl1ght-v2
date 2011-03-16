/*! \file thread.h
 \brief PPU thread management.
*/

#ifndef __SYS_THREAD_H__
#define __SYS_THREAD_H__

#include <ppu-lv2.h>
#include <lv2/thread.h>

#define THREAD_JOINABLE			1

#ifdef __cplusplus
	extern "C" {
#endif

typedef struct _sys_ppu_thread_stack_t {
	void *addr;
	u32 size;
} sys_ppu_thread_stack_t;

s32 sysThreadCreate(sys_ppu_thread_t *threadid,void (*entry)(void *),void *arg,s32 priority,u64 stacksize,u64 flags,char *threadname);

LV2_SYSCALL sysThreadJoin(sys_ppu_thread_t threadid,u64 *retval)
{
	return lv2syscall2(44,threadid,(u64)retval);;
}

LV2_SYSCALL sysThreadYield()
{
	return lv2syscall0(43);
}

LV2_SYSCALL sysThreadDetach(sys_ppu_thread_t threadid)
{
	return lv2syscall1(45,threadid);
}

LV2_SYSCALL sysThreadJoinState(s32 *joinable)
{
	return lv2syscall1(46,(u64)joinable);
}

LV2_SYSCALL sysThreadSetPriority(sys_ppu_thread_t threadid,s32 prio)
{
	return lv2syscall2(47,threadid,prio);
}

LV2_SYSCALL sysThreadGetPriority(sys_ppu_thread_t threadid,s32 *prio)
{
	return lv2syscall2(48,threadid,(u64)prio);
}

LV2_SYSCALL sysThreadRename(sys_ppu_thread_t threadid,const char *name)
{
	return lv2syscall2(56,threadid,(u64)name);
}

LV2_SYSCALL sysThreadRecoverPageFault(sys_ppu_thread_t threadid)
{
	return lv2syscall1(57,threadid);
}

LV2_SYSCALL sysThreadGetStackInformation(sys_ppu_thread_stack_t *info)
{
	s32 ret = 0;
	struct _sys_ppu_thread_stack_t_32 {
		u32 addr;
		u32 size;
	} info32;

	ret = lv2syscall1(49,(u64)(&info32));
	info->addr = (void*)((u64)info32.addr);
	info->size = info32.size;

	return ret;
}

#ifdef __cplusplus
	}
#endif

#endif
