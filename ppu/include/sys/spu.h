/*! \file spu.h
  \brief SPU management.

  Another file.
*/

#ifndef __SYS_SPU_H__
#define __SYS_SPU_H__

#include <ppu-asm.h>
#include <ppu-lv2.h>
#include <lv2/spu.h>

#define MFC_LSA									0x3004
#define MFC_EAH									0x3008
#define MFC_EAL									0x300C
#define MFC_Size								0x3010
#define MFC_Class_CMD							0x3014
#define MFC_CMD_Status							0x3014
#define MFC_QStatus								0x3104
#define Prxy_QueryType							0x3204
#define Prxy_QueryMask							0x321C
#define Prxy_TagStatus							0x322C
#define SPU_Out_MBox							0x4004
#define SPU_In_MBox								0x400C
#define SPU_MBox_Status							0x4014
#define SPU_RunCtrl								0x401C
#define SPU_Status								0x4024
#define SPU_NextPC								0x4034
#define SPU_Sig_Notify_1						0x1400C
#define SPU_Sig_Notify_2						0x1C00C

#define SPU_THREAD_ATTR_NONE					0x00
#define SPU_THREAD_ATTR_ASYNC_INT_ENABLE		0x01
#define SPU_THREAD_ATTR_DEC_SYNC_TB_ENABLE		0x02

#define SPU_SIGNAL1_OVERWRITE					0x00
#define SPU_SIGNAL1_OR							0x01
#define SPU_SIGNAL2_OVERWRITE					0x00
#define SPU_SIGNAL2_OR							0x02


#define SPU_THREAD_BASE							0xF0000000ULL
#define SPU_THREAD_OFFSET						0x00100000ULL
#define SPU_RAW_BASE							0xE0000000ULL
#define SPU_RAW_OFFSET							0x00100000ULL
#define SPU_LOCAL_OFFSET						0x00000000ULL
#define SPU_PROBLEM_OFFSET						0x00040000ULL


#define SPU_RAW_GET_BASE_OFFSET(spu) \
	(SPU_RAW_BASE + (SPU_RAW_OFFSET*(spu)))

#define SPU_RAW_GET_LOCAL_STORAGE(spu,reg) \
	(SPU_RAW_GET_BASE_OFFSET(spu) + SPU_LOCAL_OFFSET + (reg))

#define SPU_RAW_GET_PROBLEM_STORAGE(spu,reg) \
	(SPU_RAW_GET_BASE_OFFSET(spu) + SPU_PROBLEM_OFFSET + (reg))

#define SPU_THREAD_GET_BASE_OFFSET(spu) \
	(SPU_THREAD_BASE + (SPU_THREAD_OFFSET*(spu)))

#define SPU_THREAD_GET_LOCAL_STORAGE(spu,reg) \
	(SPU_THREAD_GET_BASE_OFFSET(spu) + SPU_LOCAL_OFFSET + (reg))

#define SPU_THREAD_GET_PROBLEM_STORAGE(spu,reg) \
	(SPU_THREAD_GET_BASE_OFFSET(spu) + SPU_PROBLEM_OFFSET + (reg))

#ifdef __cplusplus
extern "C" {
#endif

//! A structure containing the arguments passed to the SPU main function.
typedef struct _sys_spu_thread_arg
{
	u64 arg0;	//!< First argument.
	u64 arg1;	//!< Second argument.
	u64 arg2;	//!< Third argument.
	u64 arg3;	//!< Fourth argument.
} sysSpuThreadArgument;

typedef struct _sys_spu_thread_attr
{
	u32 nameAddress;
	u32 nameSize;
	u32 attribute;
} sysSpuThreadAttribute;

typedef struct _sys_spu_thread_group_attr
{
	u32 nameSize;
	u32 nameAddress;
	u32 groupType;
	u32 memContainer;
} sysSpuThreadGroupAttribute;

LV2_SYSCALL sysSpuInitialize(u32 spus,u32 rawspus) 
{ 
	return lv2syscall2(169,spus,rawspus); 
}

LV2_SYSCALL sysSpuRawCreate(u32 *spu,u32 *attributes)
{
	return lv2syscall2(160,(u64)spu,(u64)attributes);
}

LV2_SYSCALL sysSpuRawDestroy(u32 spu)
{
	return lv2syscall1(161,spu);
}

LV2_SYSCALL sysSpuCreateInterrupTag(u32 spu,u32 classid,u32 hardwarethread,u32 *tag)
{
	return lv2syscall4(150,spu,classid,hardwarethread,(u64)tag);
}

LV2_SYSCALL sysSpuSetIntMask(u32 spu,u32 classid,u64 mask)
{
	return lv2syscall3(151,spu,classid,mask);
}

LV2_SYSCALL sysSpuGetIntMask(u32 spu,u32 classid,u64 *mask)
{
	return lv2syscall3(152,spu,classid,(u64)mask);
}

LV2_SYSCALL sysSpuRawSetIntStat(u32 spu, u32 classid, u64 stat)
{ 
	return lv2syscall3(153, spu, classid, stat);
}

LV2_SYSCALL sysSpuRawGetIntStat(u32 spu, u32 classid, u64* stat)
{
	return lv2syscall3(154, spu, classid, (u64)stat);
}

LV2_SYSCALL sysSpuRawReadPuintMb(u32 spu, u32* value)
{
	return lv2syscall2(163, spu, (u64)value);
}

LV2_SYSCALL sysSpuRawSetConfiguration(u32 spu, u32 value)
{
	return lv2syscall2(196, spu, value);
}

LV2_SYSCALL sysSpuRawGetConfirugation(u32 spu, u32* value)
{ 
	return lv2syscall2(197, spu, (u64)value);
}

LV2_SYSCALL sysSpuRawRecoverPageFault(u32 spu)
{
	return lv2syscall1(199, spu);
}

LV2_SYSCALL sysSpuImageOpen(sysSpuImage* image, const char* path)
{ 
	return lv2syscall2(156, (u64)image, (u64)path);
}

LV2_SYSCALL sysSpuImageOpenFd(sysSpuImage* image, s32 fd, u64 offset)
{ 
	return lv2syscall3(260, (u64)image, fd, offset);
}

LV2_SYSCALL sysSpuThreadInitialize(u32* thread, u32 group, u32 spu, sysSpuImage* image, sysSpuThreadAttribute* attributes, sysSpuThreadArgument* arguments)
{
	return lv2syscall6(172, (u64)thread, group, spu, (u64)image, (u64)attributes, (u64)arguments);
}

LV2_SYSCALL sysSpuThreadSetArguments(u32 thread, sysSpuThreadArgument* arguments)
{ 
	return lv2syscall2(166, thread, (u64)arguments);
}

LV2_SYSCALL sysSpuThreadGetExitStatus(u32 thread, s32* status)
{
	return lv2syscall2(165, thread, (u64)status);
}

LV2_SYSCALL sysSpuThreadConnectEvent(u32 thread, u32 queue, u32 type, u8 spup)
{
	return lv2syscall4(191, thread, queue, type, spup);
}

LV2_SYSCALL sysSpuThreadDisconnectEvent(u32 thread, u32 type, u8 spup) 
{ 
	return lv2syscall3(192, thread, type, spup); 
}

LV2_SYSCALL sysSpuThreadBindQueue(u32 thread, u32 queue, u32 spuq_num) 
{ 
	return lv2syscall3(193, thread, queue, spuq_num); 
}

LV2_SYSCALL sysSpuThreadUnbindQueue(u32 thread, u32 spuq_num) 
{ 
	return lv2syscall2(194, thread, spuq_num); 
}

LV2_SYSCALL sysSpuThreadWriteLocalStorage(u32 thread, u32 address, u64 value, u32 type) 
{ 
	return lv2syscall4(181, thread, address, value, type); 
}

LV2_SYSCALL sysSpuThreadReadLocalStorage(u32 thread, u32 address, u64* value, u32 type) 
{ 
	return lv2syscall4(182, thread, address, (u64)value, type); 
}

LV2_SYSCALL sysSpuThreadWriteSignal(u32 thread,u32 signal,u32 value)
{
	return lv2syscall3(184,thread,signal,value);
}

LV2_SYSCALL sysSpuThreadSetConfiguration(u32 thread, u64 value) 
{ 
	return lv2syscall2(187, thread, value); 
}

LV2_SYSCALL sysSpuThreadGetConfiguration(u32 thread, u64* value) 
{ 
	return lv2syscall2(188, thread, (u64)value); 
}

LV2_SYSCALL sysSpuThreadWriteMb(u32 thread, u32 value) 
{ 
	return lv2syscall2(190, thread, value); 
}

LV2_SYSCALL sysSpuThreadRecoverPageFault(u32 thread) 
{ 
	return lv2syscall1(198, thread); 
}

LV2_SYSCALL sysSpuThreadGroupCreate(u32 *group,u32 num,u32 prio,sysSpuThreadGroupAttribute *attr)
{
	return lv2syscall4(170,(u64)group,num,prio,(u64)attr);
}

LV2_SYSCALL sysSpuThreadGroupDestroy(u32 group)
{
	return lv2syscall1(171,group);
}

LV2_SYSCALL sysSpuThreadGroupStart(u32 group)
{
	return lv2syscall1(173,group);
}

LV2_SYSCALL sysSpuThreadGroupSuspend(u32 group)
{
	return lv2syscall1(174,group);
}

LV2_SYSCALL sysSpuThreadGroupResume(u32 group)
{
	return lv2syscall1(175,group);
}

LV2_SYSCALL sysSpuThreadGroupYield(u32 group)
{
	return lv2syscall1(176,group);
}

LV2_SYSCALL sysSpuThreadGroupTerminate(u32 group,u32 value)
{
	return lv2syscall2(177,group,value);
}

LV2_SYSCALL sysSpuThreadGroupJoin(u32 group,u32 *cause,u32 *status)
{
	return lv2syscall3(178,group,(u64)cause,(u64)status);
}

LV2_SYSCALL sysSpuThreadGroupSetPriority(u32 group,u32 prio)
{
	return lv2syscall2(179,group,prio);
}

LV2_SYSCALL sysSpuThreadGroupGetPriority(u32 group,u32 *prio)
{
	return lv2syscall2(180,group,(u64)prio);
}

LV2_SYSCALL sysSpuThreadGroupConnectEvent(u32 group,u32 eventQ,u32 eventType)
{
	return lv2syscall3(185,group,eventQ,eventType);
}

LV2_SYSCALL sysSpuThreadGroupDisconnectEvent(u32 group,u32 eventType)
{
	return lv2syscall2(186,group,eventType);
}

LV2_SYSCALL sysSpuThreadGroupConnectEventAllThreads(u32 group,u32 eventQ,u64 req,u8 *spup)
{
	return lv2syscall4(251,group,eventQ,req,(u64)spup);
}

LV2_SYSCALL sysSpuThreadGroupDisonnectEventAllThreads(u32 group,u8 spup)
{
	return lv2syscall2(252,group,spup);
}

static inline void sysSpuRawWriteProblemStorage(u32 spu,u32 reg,u32 value)
{
	__write32(SPU_RAW_GET_PROBLEM_STORAGE(spu,reg),value);
}

static inline u32 sysSpuRawReadProblemStorage(u32 spu,u32 reg)
{
	return __read32(SPU_RAW_GET_PROBLEM_STORAGE(spu,reg));
}

static inline void sysSpuRawWriteLocalStorage(u32 spu,u32 reg,u32 value)
{
	__write32(SPU_RAW_GET_LOCAL_STORAGE(spu,reg),value);
}

static inline u32 sysSpuRawReadLocalStorage(u32 spu,u32 reg)
{
	return __read32(SPU_RAW_GET_LOCAL_STORAGE(spu,reg));
}

static inline void sysSpuThreadWriteProblemStorage(u32 spu,u32 reg,u32 value)
{
	__write32(SPU_THREAD_GET_PROBLEM_STORAGE(spu,reg),value);
}

static inline u32 sysSpuThreadReadProblemStorage(u32 spu,u32 reg)
{
	return __read32(SPU_THREAD_GET_PROBLEM_STORAGE(spu,reg));
}

#ifdef __cplusplus
	}
#endif

#endif
