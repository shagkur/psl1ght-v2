	.globl spu_thread_group_yield
	
spu_thread_group_yield:
	stop		0x100
	bi			$0
	