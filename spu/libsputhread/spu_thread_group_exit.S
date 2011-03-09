	.globl spu_thread_group_exit
	
spu_thread_group_exit:
	wrch		$ch28,$3
	stop		0x101
	bi			$0
	lnop
	