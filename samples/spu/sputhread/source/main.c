#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>

#include <sys/spu.h>

#include "spu_bin.h"

#define ptr2ea(x)			((u64)((void*)(x)))

static vu32 spu_sync __attribute__((aligned(128))) = 0;
static vu32 spu_response __attribute__((aligned(128))) = 0;

int main(int argc,char *argv[])
{
	u32 cause,status;
	sysSpuImage image;
	u32 thread_id,group_id;
	sysSpuThreadArgument arg = { 0, 0, 0, 0 };
	sysSpuThreadGroupAttribute grpattr = { 7+1, ptr2ea("mygroup"), 0, 0 };
	sysSpuThreadAttribute attr = { ptr2ea("mythread"), 8+1, SPU_THREAD_ATTR_NONE };

	sysSpuInitialize(6,0);
	sysSpuImageImport(&image,spu_bin,0);

	sysSpuThreadGroupCreate(&group_id,1,100,&grpattr);

	arg.arg0 = ptr2ea(&spu_sync);
	arg.arg1 = ptr2ea(&spu_response);
	sysSpuThreadInitialize(&thread_id,group_id,0,&image,&attr,&arg);
	sysSpuThreadSetConfiguration(thread_id,(SPU_SIGNAL1_OVERWRITE | SPU_SIGNAL2_OVERWRITE));

	printf("Starting SPU thread group....\n");
	sysSpuThreadGroupStart(group_id);

	printf("input value: 42\n");

	spu_sync = 0;
	sysSpuThreadWriteSignal(thread_id,0,42);

	printf("Waiting for SPU to return....\n");
	while(spu_sync==0);

	printf("output value: %d\n",spu_response);

	sysSpuThreadGroupJoin(group_id,&cause,&status);
	sysSpuImageClose(&image);

	return 0;
}
