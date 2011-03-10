#ifndef __LV2_SPU_H__
#define __LV2_SPU_H__

#include <ppu-types.h>

#define SPU_SEGMENT_TYPE_COPY				0x01
#define SPU_SEGMENT_TYPE_FILL				0x02
#define SPU_SEGMENT_TYPE_INFO				0x04

#define SPU_IMAGE_TYPE_USER					0x00
#define SPU_IMAGE_TYPE_KERNEL				0x00

#define SPU_IMAGE_PROTECT					0x00
#define SPU_IMAGE_DIRECT					0x01

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _sys_spu_segment
{
	u32 type;
	u32 lsStart;
	u32 size;
	union {
		u32 paStart;
		u32 value;
	};
} sysSpuSegment;

typedef struct _sys_spu_image
{
	u32 type;
	u32 entryPoint;
	u32 segments;
	u32 segmentCount;
} sysSpuImage;

s32 sysSpuElfGetInformation(const void *elf,u32 *entryPoint,u32 *segmentCount);
s32 sysSpuElfGetSegments(const void *elf,sysSpuSegment *segments,u32 segmentCount);

s32 sysSpuRawLoad(u32 spu,const char *path,u32 *entryPoint);
s32 sysSpuRawImageLoad(u32 spu,sysSpuImage *image);

s32 sysSpuImageClose(sysSpuImage *image);
s32 sysSpuImageImport(sysSpuImage *image,const void *elf,u32 type);

#ifdef __cplusplus
	}
#endif

#endif
