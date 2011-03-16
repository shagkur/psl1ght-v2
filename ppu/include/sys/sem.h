/*! \file sem.h
 \brief Semaphore management functions.
*/

#ifndef __SYS_SEM_H__
#define __SYS_SEM_H__

#include <ppu-lv2.h>

#define SYS_SEM_ATTR_PROTOCOL			0x0002
#define SYS_SEM_ATTR_PSHARED			0x0200

#ifdef __cplusplus
	extern "C" {
#endif

typedef u32 sys_sem_t;

typedef struct sys_sem_attr
{
	u32 attr_protocol;
	u32 attr_pshared;
	u64 key;
	s32 flags;
	u32 pad;
	char name[8];
} sys_sem_attr_t;

LV2_SYSCALL sysSemCreate(sys_sem_t *sem,const sys_sem_attr_t *attr,s32 initial_val,s32 max_val)
{
	return lv2syscall4(90,(u64)sem,(u64)attr,initial_val,max_val);
}

LV2_SYSCALL sysSemDestroy(sys_sem_t sem)
{
	return lv2syscall1(91,sem);
}

LV2_SYSCALL sysSemWait(sys_sem_t sem,u64 timeout_usec)
{
	return lv2syscall2(92,sem,timeout_usec);
}

LV2_SYSCALL sysSemTryWait(sys_sem_t sem)
{
	return lv2syscall1(93,sem);
}

LV2_SYSCALL sysSemPost(sys_sem_t sem,s32 count)
{
	return lv2syscall2(94,sem,count);
}

LV2_SYSCALL sysSemGetValue(sys_sem_t sem,s32 *count)
{
	return lv2syscall2(114,sem,(u64)count);
}

#ifdef __cplusplus
	}
#endif

#endif
