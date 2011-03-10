#ifndef __SYS_EVENT_QUEUE_H__
#define __SYS_EVENT_QUEUE_H__

#include <ppu-lv2.h>

#ifdef __cplusplus
	extern "C" {
#endif

typedef u32 sys_event_queue_t;

typedef struct sys_event
{
	u64 source;
	u64 data_1;
	u64 data_2;
	u64 data_3;
} sys_event_t;

LV2_SYSCALL sysEventQueueDestroy(sys_event_queue_t eventQ,s32 mode)
{
	return lv2syscall2(129,eventQ,mode);
}

LV2_SYSCALL sysEventQueueReceive(sys_event_queue_t eventQ,sys_event_t *event,u64 timeout_usec)
{
	return lv2syscall3(130,eventQ,(u64)event,timeout_usec);
}

LV2_SYSCALL sysEventQueueDrain(sys_event_queue_t eventQ)
{
	return lv2syscall1(133,eventQ);
}

#ifdef __cplusplus
	}
#endif

#endif
