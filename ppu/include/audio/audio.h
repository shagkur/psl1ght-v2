#ifndef __LV2_AUDIO_H__
#define __LV2_AUDIO_H__

#include <sys/event_queue.h>

#define AUDIO_BLOCK_SAMPLES				256

#define AUDIO_STATUS_READY				1
#define AUDIO_STATUS_RUN				2
#define AUDIO_STATUS_CLOSE				0x1010

#define AUDIO_PORT_2CH					2
#define AUDIO_PORT_8CH					8

#define AUDIO_BLOCK_8					8
#define AUDIO_BLOCK_16					16
#define AUDIO_BLOCK_32					32

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _audio_port_param
{
	u64 numChannels;
	u64 numBlocks;
	u64 attrib;
	f32 level;
} audioPortParam;

typedef struct _audio_port_config
{
	u32 readIndex;
	u32 status;
	u64 channelCount;
	u64 numBlocks;
	u32 portSize;
	u32 audioDataStart;
} audioPortConfig;

s32 audioInit();
s32 audioQuit();
s32 audioPortOpen(audioPortParam *param,u32 *portNum);
s32 audioPortStart(u32 portNum);
s32 audioPortStop(u32 portNum);
s32 audioGetPortConfig(u32 portNum,audioPortConfig *config);
s32 audioPortClose(u32 portNum);
s32 audioCreateNotifyEventQueue(sys_event_queue_t *eventQ,u64 *queueKey);
s32 audioSetNotifyEventQueue(u64 queueKey);
s32 audioRemoveNotifyEventQueue(u64 queueKey);

#ifdef __cplusplus
	}
#endif

#endif
