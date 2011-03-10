#ifndef __SYS_SYSTIME_H__
#define __SYS_SYSTIME_H__

#include <ppu-lv2.h>
#include <lv2/systime.h>

#ifdef __cplusplus
extern "C" {
#endif

LV2_INLINE u64 sysGetTimebaseFrequency()
{
	return lv2syscall0(147);
}

LV2_SYSCALL sysGetCurrentTime(s64 *sec,s64 *nsec)
{
	return lv2syscall2(145,(u64)sec,(u64)nsec);
}

#ifdef __cplusplus
	}
#endif

#endif
