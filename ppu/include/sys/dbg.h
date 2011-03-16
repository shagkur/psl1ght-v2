/*! \file dbg.h
 \brief Debugging management functions.
*/

#ifndef __SYS_DBG_H__
#define __SYS_DBG_H__

#include <ppu-types.h>
#include <sys/thread.h>
#include <sys/event_queue.h>

#define SYS_DBG_PPU_NUM_GPR			32
#define SYS_DBG_PPU_NUM_FPR			32
#define SYS_DBG_PPU_NUM_VR			32
#define SYS_DBG_PPU_VR_WIDTH		16

#define SYS_DBG_SPU_NUM_GPR			128
#define SYS_DBG_SPU_NUM_MFC_CQ_SR	96
#define SYS_DBG_SPU_GPR_WIDTH		16
#define SYS_DBG_SPU_NUM_MB			4

#ifdef __cplusplus
extern "C" {
#endif

typedef enum
{
	PPU_THREAD_STATUS_IDLE,
	PPU_THREAD_STATUS_RUNNABLE,
	PPU_THREAD_STATUS_ONPROC,
	PPU_THREAD_STATUS_SLEEP,
	PPU_THREAD_STATUS_STOP,
	PPU_THREAD_STATUS_ZOMBIE,
	PPU_THREAD_STATUS_DELETED,
	PPU_THREAD_STATUS_UNKNOWN
} sys_dbg_ppu_thread_status_t;

typedef enum
{
	SPU_THREAD_GROUP_STATUS_NOTINITIALIZED,
	SPU_THREAD_GROUP_STATUS_INITIALIZED,
	SPU_THREAD_GROUP_STATUS_READY,
	SPU_THREAD_GROUP_STATUS_WAITING,
	SPU_THREAD_GROUP_STATUS_SUSPENDED,
	SPU_THREAD_GROUP_STATUS_WAITING_AND_SUSPENDED,
	SPU_THREAD_GROUP_STATUS_RUNNING,
	SPU_THREAD_GROUP_STATUS_STOPPED,
	SPU_THREAD_GROUP_STATUS_UNKNOWN,
} sys_dbg_spu_thread_group_status_t;

typedef union
{
	u8 byte[SYS_DBG_PPU_VR_WIDTH];
	u16 halfword[SYS_DBG_PPU_VR_WIDTH/sizeof(u16)];
	u32 word[SYS_DBG_PPU_VR_WIDTH/sizeof(u32)];
	u64 dword[SYS_DBG_PPU_VR_WIDTH/sizeof(u64)];
} sys_dbg_vr_t;

typedef union
{
	u8 byte[SYS_DBG_SPU_GPR_WIDTH];
	u16 halfword[SYS_DBG_SPU_GPR_WIDTH/sizeof(u16)];
	u32 word[SYS_DBG_SPU_GPR_WIDTH/sizeof(u32)];
	u64 dword[SYS_DBG_SPU_GPR_WIDTH/sizeof(u64)];
} sys_dbg_spu_gpr_t;

typedef struct _sys_dbg_ppu_thread_context
{
	u64 gpr[SYS_DBG_PPU_NUM_GPR];
	u32 cr;
	u32 xer;
	u32 lr;
	u32 ctr;
	u32 pc;
	u64 fpr[SYS_DBG_PPU_NUM_FPR];
	u32 fpscr;
	sys_dbg_vr_t vr[SYS_DBG_PPU_NUM_VR];
	sys_dbg_vr_t vscr;
} sys_dbg_ppu_thread_context_t;

typedef struct _sys_dbg_spu_thread_context
{
	sys_dbg_spu_gpr_t gpr[SYS_DBG_SPU_NUM_GPR];
	u32 npc;
	u32 fpscr;
	u32 srr0;
	u32 spu_status;
	u64 spu_cfg;
	u32 mb_stat;
	u32 ppu_mb;
	u32 spu_mb[SYS_DBG_SPU_NUM_MB];
	u32 decrementer;
	u64 mfc_cq_sr[SYS_DBG_SPU_NUM_MFC_CQ_SR];
} sys_dbg_ppu_thread_context_t;

typedef void (*dbg_exception_handler_t)(u64 cause,sys_ppu_thread_t tid,u64 dar);

s32 sysDbgSetStacksizePPUExceptionHandler(size_t stacksize);
s32 sysDbgGetSPUThreadGroupIds(u32 *group_ids,u64 *num_ids,u64 *num_all_ids);
s32 sysDbgGetPPUThreadIds(sys_ppu_thread_t *ids,u64 *num_ids,u64 *num_all_ids);
s32 sysDbgGetSPUThreadIds(u32 group_id,u32 *thread_ids,u64 *num_ids,u64 *num_all_ids);
s32 sysDbgRegisterPPUExceptionHandler(dbg_exception_handler_t handler,u64 flags);
//s32 sysDbgGetEventQueueInformation();
s32 sysDbgGetPPUThreadName(sys_ppu_thread_t id,char *name);
s32 sysDbgGetSPUThreadName(u32 thread_id,char *name);
//s32 sysDbgGetMutexInformation();
//s32 sysDbgGetCondInformation();
s32 sysDbgGetPPUThreadStatus(sys_ppu_thread_t id,sys_dbg_ppu_thread_status_t *status);
//s32 sysDbgGetRWLockInformation();
s32 sysDbgGetGetSPUThreadGroupStatus(u32 group_id,sys_dbg_spu_thread_group_status_t *status);
//s32 sysDbgGetSemaphoreInformation();
s32 sysDbgGetSPUThreadGroupName(u32 group_id,char *name);
s32 sysDbgFinalizePPUExceptionHandler();
s32 sysDbgReadSPUThreadContext(u32 thread_id,sys_dbg_spu_thread_context_t *context);
s32 sysDbgInitializePPUExceptionHandler(s32 prio);
s32 sysDbgReadPPUThreadContext(sys_ppu_thread_t id,sys_dbg_ppu_thread_context_t *context);
s32 sysDbgUnregisterPPUExceptionHandler();
//s32 sysDbgGetLwMutexInformation();

#ifdef __cplusplus
	}
#endif

#endif
