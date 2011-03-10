#ifndef __PPU_LV2_H__
#define __PPU_LV2_H__

#include <ppu-types.h>
#include <ppc-asm.h>

#define LV2_INLINE static inline __attribute__((unused))
#define LV2_SYSCALL LV2_INLINE s32

#define __lv2syscallarg0
#define __lv2syscallarg1 __lv2syscallarg0, u64 a1
#define __lv2syscallarg2 __lv2syscallarg1, u64 a2
#define __lv2syscallarg3 __lv2syscallarg2, u64 a3
#define __lv2syscallarg4 __lv2syscallarg3, u64 a4
#define __lv2syscallarg5 __lv2syscallarg4, u64 a5
#define __lv2syscallarg6 __lv2syscallarg5, u64 a6
#define __lv2syscallarg7 __lv2syscallarg6, u64 a7
#define __lv2syscallarg8 __lv2syscallarg7, u64 a8

#define __lv2syscallclobber8 "r0","r2","r12","lr","ctr","xer","cr0","cr1","cr5","cr6","cr7","memory"
#define __lv2syscallclobber7 __lv2syscallclobber8,"r10"
#define __lv2syscallclobber6 __lv2syscallclobber7,"r9"
#define __lv2syscallclobber5 __lv2syscallclobber6,"r8"
#define __lv2syscallclobber4 __lv2syscallclobber5,"r7"
#define __lv2syscallclobber3 __lv2syscallclobber4,"r6"
#define __lv2syscallclobber2 __lv2syscallclobber3,"r5"
#define __lv2syscallclobber1 __lv2syscallclobber2,"r4"
#define __lv2syscallclobber0 __lv2syscallclobber1,"r3"

#define __lv2syscallparam1(reg) reg(p1)
#define __lv2syscallparam2(reg) __lv2syscallparam1(reg),reg(p2)
#define __lv2syscallparam3(reg) __lv2syscallparam2(reg),reg(p3)
#define __lv2syscallparam4(reg) __lv2syscallparam3(reg),reg(p4)
#define __lv2syscallparam5(reg) __lv2syscallparam4(reg),reg(p5)
#define __lv2syscallparam6(reg) __lv2syscallparam5(reg),reg(p6)
#define __lv2syscallparam7(reg) __lv2syscallparam6(reg),reg(p7)
#define __lv2syscallparam8(reg) __lv2syscallparam7(reg),reg(p8)

#define __lv2syscall "r"(s)

#define __lv2syscallreg(num,reg) \
	register u64 p##num asm(reg) = a##num
#define __lv2syscallregs(sys) \
	register u64 s asm("11") = (sys)

LV2_INLINE u64 lv2syscall0(u64 syscall __lv2syscallarg0)
{
	__lv2syscallregs(syscall);
	register u64 p1 asm("3") = 0;
	
	__asm__ __volatile__ (
		"sc"
		: __lv2syscallparam1("=r")
		: __lv2syscall
		: __lv2syscallclobber1
	);
	return p1;
}

LV2_INLINE u64 lv2syscall1(u64 syscall __lv2syscallarg1)
{
	__lv2syscallregs(syscall);
	__lv2syscallreg(1,"3");
	
	__asm__ __volatile__ (
		"sc"
		: __lv2syscallparam1("=r")
		: __lv2syscallparam1("r"),__lv2syscall
		: __lv2syscallclobber1
	);
	return p1;
}

LV2_INLINE u64 lv2syscall2(u64 syscall __lv2syscallarg2)
{
	__lv2syscallregs(syscall);
	__lv2syscallreg(1,"3");
	__lv2syscallreg(2,"4");
	
	__asm__ __volatile__ (
		"sc"
		: __lv2syscallparam2("=r")
		: __lv2syscallparam2("r"),__lv2syscall
		: __lv2syscallclobber2
	);
	return p1;
}

LV2_INLINE u64 lv2syscall3(u64 syscall __lv2syscallarg3)
{
	__lv2syscallregs(syscall);
	__lv2syscallreg(1,"3");
	__lv2syscallreg(2,"4");
	__lv2syscallreg(3,"5");
	
	__asm__ __volatile__ (
		"sc"
		: __lv2syscallparam3("=r")
		: __lv2syscallparam3("r"),__lv2syscall
		: __lv2syscallclobber3
	);
	return p1;
}

LV2_INLINE u64 lv2syscall4(u64 syscall __lv2syscallarg4)
{
	__lv2syscallregs(syscall);
	__lv2syscallreg(1,"3");
	__lv2syscallreg(2,"4");
	__lv2syscallreg(3,"5");
	__lv2syscallreg(4,"6");
	
	__asm__ __volatile__ (
		"sc"
		: __lv2syscallparam4("=r")
		: __lv2syscallparam4("r"),__lv2syscall
		: __lv2syscallclobber4
	);
	return p1;
}

LV2_INLINE u64 lv2syscall5(u64 syscall __lv2syscallarg5)
{
	__lv2syscallregs(syscall);
	__lv2syscallreg(1,"3");
	__lv2syscallreg(2,"4");
	__lv2syscallreg(3,"5");
	__lv2syscallreg(4,"6");
	__lv2syscallreg(5,"7");
	
	__asm__ __volatile__ (
		"sc"
		: __lv2syscallparam5("=r")
		: __lv2syscallparam5("r"),__lv2syscall
		: __lv2syscallclobber5
	);
	return p1;
}

LV2_INLINE u64 lv2syscall6(u64 syscall __lv2syscallarg6)
{
	__lv2syscallregs(syscall);
	__lv2syscallreg(1,"3");
	__lv2syscallreg(2,"4");
	__lv2syscallreg(3,"5");
	__lv2syscallreg(4,"6");
	__lv2syscallreg(5,"7");
	__lv2syscallreg(6,"8");
	
	__asm__ __volatile__ (
		"sc"
		: __lv2syscallparam6("=r")
		: __lv2syscallparam6("r"),__lv2syscall
		: __lv2syscallclobber6
	);
	return p1;
}

LV2_INLINE u64 lv2syscall7(u64 syscall __lv2syscallarg7)
{
	__lv2syscallregs(syscall);
	__lv2syscallreg(1,"3");
	__lv2syscallreg(2,"4");
	__lv2syscallreg(3,"5");
	__lv2syscallreg(4,"6");
	__lv2syscallreg(5,"7");
	__lv2syscallreg(6,"8");
	__lv2syscallreg(7,"9");
	
	__asm__ __volatile__ (
		"sc"
		: __lv2syscallparam7("=r")
		: __lv2syscallparam7("r"),__lv2syscall
		: __lv2syscallclobber7
	);
	return p1;
}

LV2_INLINE u64 lv2syscall8(u64 syscall __lv2syscallarg8)
{
	__lv2syscallregs(syscall);
	__lv2syscallreg(1,"3");
	__lv2syscallreg(2,"4");
	__lv2syscallreg(3,"5");
	__lv2syscallreg(4,"6");
	__lv2syscallreg(5,"7");
	__lv2syscallreg(6,"8");
	__lv2syscallreg(7,"9");
	__lv2syscallreg(8,"10");
	
	__asm__ __volatile__ (
		"sc"
		: __lv2syscallparam8("=r")
		: __lv2syscallparam8("r"),__lv2syscall
		: __lv2syscallclobber8
	);
	return p1;
}

#endif
