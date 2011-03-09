#ifndef __SPU_THREAD_H__
#define __SPU_THREAD_H__

#include <sys/cdefs.h>

#ifdef __cplusplus
extern "C" {
#endif

void spu_thread_group_exit(int status);
void spu_thread_group_yield(void);
void spu_thread_exit(int status);

#ifdef __cplusplus
	}
#endif

#endif
