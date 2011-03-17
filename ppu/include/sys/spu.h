/*! \file spu.h
  \brief SPU management.

  These are the LV2 syscalls for SPU management (raw SPUs and SPU threads).
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

//! No thread attributes
#define SPU_THREAD_ATTR_NONE					0x00
#define SPU_THREAD_ATTR_ASYNC_INT_ENABLE		0x01
#define SPU_THREAD_ATTR_DEC_SYNC_TB_ENABLE		0x02

//! Configure signal notification register 1 to overwrite mode
#define SPU_SIGNAL1_OVERWRITE					0x00
//! Configure signal notification register 1 to OR mode
#define SPU_SIGNAL1_OR							0x01
//! Configure signal notification register 2 to overwrite mode
#define SPU_SIGNAL2_OVERWRITE					0x00
//! Configure signal notification register 2 to OR mode
#define SPU_SIGNAL2_OR							0x02


#define SPU_THREAD_BASE							0xF0000000ULL
#define SPU_THREAD_OFFSET						0x00100000ULL
#define SPU_RAW_BASE							0xE0000000ULL
#define SPU_RAW_OFFSET							0x00100000ULL
#define SPU_LOCAL_OFFSET						0x00000000ULL
#define SPU_PROBLEM_OFFSET						0x00040000ULL

#define SPU_RAW_GET_BASE_OFFSET(spu) \
	(SPU_RAW_BASE + (SPU_RAW_OFFSET*(spu)))

//! Returns the memory-mapped address of local storage of a raw SPU.
#define SPU_RAW_GET_LOCAL_STORAGE(spu,reg) \
	(SPU_RAW_GET_BASE_OFFSET(spu) + SPU_LOCAL_OFFSET + (reg))

//! Returns the memory-mapped address of problem storage of a raw SPU.
#define SPU_RAW_GET_PROBLEM_STORAGE(spu,reg) \
	(SPU_RAW_GET_BASE_OFFSET(spu) + SPU_PROBLEM_OFFSET + (reg))

#define SPU_THREAD_GET_BASE_OFFSET(spu) \
	(SPU_THREAD_BASE + (SPU_THREAD_OFFSET*(spu)))

//! Returns the memory-mapped address of local storage of a SPU thread.
#define SPU_THREAD_GET_LOCAL_STORAGE(spu,reg) \
	(SPU_THREAD_GET_BASE_OFFSET(spu) + SPU_LOCAL_OFFSET + (reg))

//! Returns the memory-mapped address of problem storage of a SPU thread.
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

/*! \brief A structure containing SPU thread attributes.

 Possible values for \p attribute flags are \ref SPU_THREAD_ATTR_NONE or an
 OR'ed list of the following flags:
   - \ref SPU_THREAD_ATTR_ASYNC_INT_ENABLE
   - \ref SPU_THREAD_ATTR_DEC_SYNC_TB_ENABLE
*/
typedef struct _sys_spu_thread_attr
{
	u32 nameAddress;	//!< Effective address of the thread's name string.
	u32 nameSize;		//!< Size of the name string in bytes (including terminating null byte).
	u32 attribute;		//!< OR'ed list of SPU thread attribute flags (or \ref SPU_THREAD_ATTR_NONE)
} sysSpuThreadAttribute;

//! A structure containing SPU thread group attributes.
typedef struct _sys_spu_thread_group_attr
{
	u32 nameSize;		//!< Size of the name string in bytes (including terminating null byte).
	u32 nameAddress;	//!< Effective address of the thread group's name string.
	u32 groupType;
	u32 memContainer;
} sysSpuThreadGroupAttribute;

/*! \brief Initialize the SPU management.
 \param spus
 Total number of needed SPUs (from 1 to 6).
 \param rawspus
 Number of required raw SPUs (from 1 to 5).
 \return
 zero if no error occured, nonzero otherwise.
*/
LV2_SYSCALL sysSpuInitialize(u32 spus,u32 rawspus) 
{ 
	return lv2syscall2(169,spus,rawspus); 
}

/*! \brief Allocate a raw SPU.
 \param spu
 Pointer to a returned raw SPU identifier.
 \param attributes
 Pointer to an attributes structure (or \c NULL if default attributes are used).
 \return
 zero if no error occured, nonzero otherwise.
*/
LV2_SYSCALL sysSpuRawCreate(u32 *spu,u32 *attributes)
{
	return lv2syscall2(160,(u64)spu,(u64)attributes);
}

/*! \brief De-allocate a raw SPU.
 \param spu
 The raw SPU identifier.
 \return
 zero if no error occured, nonzero otherwise.
*/
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

/*! \brief Create a SPU image from an ELF file.
 \param image
 Pointer to the SPU image structure.
 \param path
 The pathname of the ELF file to be read from.
 \return
 zero if no error occured, nonzero otherwise.
*/
LV2_SYSCALL sysSpuImageOpen(sysSpuImage* image, const char* path)
{ 
	return lv2syscall2(156, (u64)image, (u64)path);
}

/*! \brief Create a SPU image from an open binary file.
 \param image
 Pointer to the SPU image structure.
 \param fd
 File descriptor of the opened file.
 \param offset
 Offset to the beginning of the SPU image in the file.
 \return
 zero if no error occured, nonzero otherwise.
*/
LV2_SYSCALL sysSpuImageOpenFd(sysSpuImage* image, s32 fd, u64 offset)
{ 
	return lv2syscall3(260, (u64)image, fd, offset);
}

/*! \brief Initialize a SPU thread.
 \param thread
 Pointer to the returned thread identifier.
 \param group
 Group identifier.
 \param spu
 Index of thread in group (from 0 to the thread group size minus 1).
 \param image
 Pointer to the SPU image structure.
 \param attributes
 Pointer to a SPU thread attribute structure.
 \param arguments
 Pointer to the arguments for the thread's main function.
 \return
 zero if no error occured, nonzero otherwise.
*/
LV2_SYSCALL sysSpuThreadInitialize(u32* thread, u32 group, u32 spu, sysSpuImage* image, sysSpuThreadAttribute* attributes, sysSpuThreadArgument* arguments)
{
	return lv2syscall6(172, (u64)thread, group, spu, (u64)image, (u64)attributes, (u64)arguments);
}

/*! \brief Set the SPU thread arguments.
 \param thread
 Thread identifier.
 \param arguments
 Pointer to the arguments list.
 \return
 zero if no error occured, nonzero otherwise.
*/
LV2_SYSCALL sysSpuThreadSetArguments(u32 thread, sysSpuThreadArgument* arguments)
{ 
	return lv2syscall2(166, thread, (u64)arguments);
}

/*! \brief Get the exit status of a thread.

 The exit status is the value the SPU program used as an argument to spu_thread_exit.
 \param thread
 Thread identifier.
 \param arguments
 Pointer to the returned exit status.
 \return
 zero if no error occured, nonzero otherwise.
*/
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

/*! \brief Write a value to a SPU thread's local store memory.

 \param thread
 Thread identifier.
 \param address
 Address in local store to write to.
 \param value
 Value to be written.
 \param type
 Type of value to be written.
 \return
 zero if no error occured, nonzero otherwise.
*/
LV2_SYSCALL sysSpuThreadWriteLocalStorage(u32 thread, u32 address, u64 value, u32 type) 
{ 
	return lv2syscall4(181, thread, address, value, type); 
}

/*! \brief Read a value From the SPU thread's local store memory.

 \param thread
 Thread identifier.
 \param address
 Address in local store to read from.
 \param value
 Pointer to read value.
 \param type
 Type of value to be read.
 \return
 zero if no error occured, nonzero otherwise.
*/
LV2_SYSCALL sysSpuThreadReadLocalStorage(u32 thread, u32 address, u64* value, u32 type) 
{ 
	return lv2syscall4(182, thread, address, (u64)value, type); 
}

/*! \brief Write to the SPU thread's signal notification register.

 \param thread
 Thread identifier.
 \param signal
  - 0 : write to signal notification register 1
  - 1 : write to signal notification register 2
 \param value
 Value to be written.
 \return
 zero if no error occured, nonzero otherwise.
*/
LV2_SYSCALL sysSpuThreadWriteSignal(u32 thread,u32 signal,u32 value)
{
	return lv2syscall3(184,thread,signal,value);
}

/*! \brief Configure the SPU thread's signal notification.

 \param thread
 Thread identifier.
 \param value
 A OR combination of the following values:
  - \ref SPU_SIGNAL1_OVERWRITE
  - \ref SPU_SIGNAL1_OR
  - \ref SPU_SIGNAL2_OVERWRITE
  - \ref SPU_SIGNAL2_OR
 \return
 zero if no error occured, nonzero otherwise.
*/
LV2_SYSCALL sysSpuThreadSetConfiguration(u32 thread, u64 value) 
{ 
	return lv2syscall2(187, thread, value); 
}

/*! \brief Get the configuration of the SPU thread's signal notification.

 \param thread
 Thread identifier.
 \param value
 Pointer to the read configuration value, which is a OR combination of the
 following values:
  - \ref SPU_SIGNAL1_OVERWRITE
  - \ref SPU_SIGNAL1_OR
  - \ref SPU_SIGNAL2_OVERWRITE
  - \ref SPU_SIGNAL2_OR
 \return
 zero if no error occured, nonzero otherwise.
*/
LV2_SYSCALL sysSpuThreadGetConfiguration(u32 thread, u64* value) 
{ 
	return lv2syscall2(188, thread, (u64)value); 
}

/*! \brief Write to the SPU thread's inbound mailbox register.

 \param thread
 Thread identifier.
 \param value
 Value to be written.
 \return
 zero if no error occured, nonzero otherwise.
*/
LV2_SYSCALL sysSpuThreadWriteMb(u32 thread, u32 value) 
{ 
	return lv2syscall2(190, thread, value); 
}

/*! \brief Recover from a SPU thread page fault.

 \param thread
 Thread identifier.
 \return
 zero if no error occured, nonzero otherwise.
*/
LV2_SYSCALL sysSpuThreadRecoverPageFault(u32 thread) 
{ 
	return lv2syscall1(198, thread); 
}

/*! \brief Create a SPU thread group.

 \param group
 Pointer to the returned SPU thread group identifier.
 \param num
 Number of SPU threads in the thread group.
 \param prio
 Priority of the thread group.
 \param attr
 Pointer to a SPU thread group attribute structure.
 \return
 zero if no error occured, nonzero otherwise.
*/
LV2_SYSCALL sysSpuThreadGroupCreate(u32 *group,u32 num,u32 prio,sysSpuThreadGroupAttribute *attr)
{
	return lv2syscall4(170,(u64)group,num,prio,(u64)attr);
}

/*! \brief Destroy a SPU thread group.

 \param group
 SPU thread group identifier.
 \return
 zero if no error occured, nonzero otherwise.
*/
LV2_SYSCALL sysSpuThreadGroupDestroy(u32 group)
{
	return lv2syscall1(171,group);
}

/*! \brief Start a SPU thread group.

 \param group
 SPU thread group identifier.
 \return
 zero if no error occured, nonzero otherwise.
*/
LV2_SYSCALL sysSpuThreadGroupStart(u32 group)
{
	return lv2syscall1(173,group);
}

/*! \brief Suspend a SPU thread group.

 \param group
 SPU thread group identifier.
 \return
 zero if no error occured, nonzero otherwise.
*/
LV2_SYSCALL sysSpuThreadGroupSuspend(u32 group)
{
	return lv2syscall1(174,group);
}

/*! \brief Resume a SPU thread group.

 \param group
 SPU thread group identifier.
 \return
 zero if no error occured, nonzero otherwise.
*/
LV2_SYSCALL sysSpuThreadGroupResume(u32 group)
{
	return lv2syscall1(175,group);
}

/*! \brief Yield a SPU thread group.

 \param group
 SPU thread group identifier.
 \return
 zero if no error occured, nonzero otherwise.
*/
LV2_SYSCALL sysSpuThreadGroupYield(u32 group)
{
	return lv2syscall1(176,group);
}

/*! \brief Terminate a SPU thread group.

 \param group
 SPU thread group identifier.
 \return
 zero if no error occured, nonzero otherwise.
*/
LV2_SYSCALL sysSpuThreadGroupTerminate(u32 group,u32 value)
{
	return lv2syscall2(177,group,value);
}

/*! \brief Wait for a SPU thread group to finish its execution.

 \param group
 SPU thread group identifier.
 \param cause
 Pointer to returned cause of thread group termination.
 \param status
 Pointer to returned status of thread group termination.
 \return
 zero if no error occured, nonzero otherwise.
*/
LV2_SYSCALL sysSpuThreadGroupJoin(u32 group,u32 *cause,u32 *status)
{
	return lv2syscall3(178,group,(u64)cause,(u64)status);
}

/*! \brief Set a SPU thread group's priority.

 \param group
 SPU thread group identifier.
 \param prio
 New priority value.
 \return
 zero if no error occured, nonzero otherwise.
*/
LV2_SYSCALL sysSpuThreadGroupSetPriority(u32 group,u32 prio)
{
	return lv2syscall2(179,group,prio);
}

/*! \brief Get a SPU thread group's priority.

 \param group
 SPU thread group identifier.
 \param prio
 Pointer to returned priority value.
 \return
 zero if no error occured, nonzero otherwise.
*/
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

/*! \brief Get a SPU thread group's priority.

 \param group
 SPU thread group identifier.
 \param prio
 Pointer to returned priority value.
 \return
 zero if no error occured, nonzero otherwise.
*/

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
