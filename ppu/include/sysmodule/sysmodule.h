#ifndef __LV2_SYSMODULE_H__
#define __LV2_SYSMODULE_H__

#include <ppu-types.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef enum
{
	SYSMODULE_NET = 0,

	SYSMODULE_RTC = 9,

	SYSMODULE_SYNC = 0xd,
	SYSMODULE_FS,
	SYSMODULE_JPGDEC,
	SYSMODULE_GCM_SYS,
	SYSMODULE_AUDIO,

	SYSMODULE_NETCTL = 0x14,
	SYSMODULE_SYSUTIL,
	SYSMODULE_SYSUTIL_NP,
	SYSMODULE_IO,
	SYSMODULE_PNGDEC,

	SYSMODULE_USBD = 0x1c,

	SYSMODULE_CAM = 0x23
} sysModuleId;

s32 sysModuleLoad(sysModuleId id);
s32 sysModuleUnload(sysModuleId id);

#ifdef __cplusplus
	}
#endif

#endif
