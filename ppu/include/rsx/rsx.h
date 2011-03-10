#ifndef __RSX_H__
#define __RSX_H__

#include <rsx/mm.h>
#include <rsx/gcm_sys.h>
#include <rsx/rsx_program.h>
#include <rsx/commands.h>

#ifdef __cplusplus
extern "C" {
#endif

gcmContextData* rsxInit(const u32 cmdSize,const u32 ioSize,const void *ioAddress);

s32 rsxAddressToOffset(void *ptr,u32 *offset);
void rsxFlushBuffer(gcmContextData *context);
void rsxResetCommandBuffer(gcmContextData *context);
void rsxFinish(gcmContextData *context,u32 ref_value);
void rsxSetupContextData(gcmContextData *context,const u32 *addr,const u32 size,gcmContextCallback cb);

#ifdef __cplusplus
	}
#endif

#endif
