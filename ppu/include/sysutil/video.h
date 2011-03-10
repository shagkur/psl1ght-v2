#ifndef __LV2_VIDEO_H__
#define __LV2_VIDEO_H__

#include <ppu-types.h>

#define VIDEO_STATE_DISABLED			0
#define VIDEO_STATE_ENABLED				1
#define VIDEO_STATE_BUSY				3

#define VIDEO_BUFFER_FORMAT_XRGB		0
#define VIDEO_BUFFER_FORMAT_XBGR		1
#define VIDEO_BUFFER_FORMAT_FLOAT		2

#define VIDEO_ASPECT_AUTO				0
#define VIDEO_ASPECT_4_3				1
#define VIDEO_ASPECT_16_9				2

#define VIDEO_RESOLUTION_1080			1
#define VIDEO_RESOLUTION_720			2
#define VIDEO_RESOLUTION_480			4
#define VIDEO_RESOLUTION_576			5

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _videoresolution
{
	u16 width;
	u16 height;
} VideoResolution;

typedef struct _videodisplaymode
{
	u8 resolution;
	u8 scanMode;
	u8 conversion;
	u8 aspect;
	u8 padding[2];
	u16 refreshRates;
} VideoDisplayMode;

typedef struct _videostate
{
	u8 state;
	u8 colorSpace;
	u8 padding[6];
	VideoDisplayMode displayMode;
} VideoState;

typedef struct _videoconfig
{
	u8 resolution;
	u8 format;
	u8 aspect;
	u8 padding[9];
	u32 pitch;
} VideoConfiguration;

int videoGetState(int videoOut,int deviceIndex,VideoState *state);
int videoGetResolution(int resolutionId,VideoResolution *resolution);
int videoConfigure(int videoOut,VideoConfiguration *config,void *option,int blocking);

#ifdef __cplusplus
	}
#endif

#endif
