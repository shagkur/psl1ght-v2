#ifndef __GCM_SYS_H__
#define __GCM_SYS_H__

#include <ppu-types.h>

#define GCM_TRUE								1
#define GCM_FALSE								0

#define GCM_FLIP_HSYNC							1
#define GCM_FLIP_VSYNC							2
#define GCM_FLIP_HSYNC_AND_BREAK_EVERYTHING		3

#define GCM_MAX_MRT_COUNT						4

#define GCM_DMA_MEMORY_FRAME_BUFFER				(0xFEED0000)
#define GCM_DMA_MEMORY_HOST_BUFFER				(0xFEED0001)

#define GCM_TF_COLOR_R5G5B5						3
#define GCM_TF_COLOR_X8R8G8B8					5
#define GCM_TF_COLOR_A8R8G8B8					8

#define GCM_TF_ZETA_Z16							1
#define GCM_TF_ZETA_Z24S8						2

#define GCM_TF_TYPE_LINEAR						1
#define GCM_TF_TYPE_SWIZZLE						2

#define GCM_LOCATION_RSX						0
#define GCM_LOCATION_CELL						1

#define GCM_TF_TARGET_NONE						0
#define GCM_TF_TARGET_0							1
#define GCM_TF_TARGET_1							2
#define GCM_TF_TARGET_MRT1						0x13
#define GCM_TF_TARGET_MRT2						0x17
#define GCM_TF_TARGET_MRT3						0x1f

#define GCM_TF_CENTER_1							0

#define	GCM_COLOR_MASK_B						0x00000001
#define	GCM_COLOR_MASK_G						0x00000100
#define	GCM_COLOR_MASK_R						0x00010000
#define	GCM_COLOR_MASK_A						0x01000000

#define GCM_CLEAR_Z								0x01
#define GCM_CLEAR_S								0x02
#define GCM_CLEAR_R								0x10
#define GCM_CLEAR_G								0x20
#define GCM_CLEAR_B								0x40
#define GCM_CLEAR_A								0x80
#define GCM_CLEAR_M								0xf3

#define GCM_NEVER								0x0200
#define GCM_LESS								0x0201
#define GCM_EQUAL								0x0202
#define GCM_LEQUAL								0x0203
#define GCM_GREATER								0x0204
#define GCM_NOTEQUAL							0x0205
#define GCM_GEQUAL								0x0206
#define GCM_ALWAYS								0x0207

#define GCM_CULL_FRONT							0x0404
#define GCM_CULL_BACK							0x0405
#define GCM_CULL_ALL							0x0408

#define GCM_FRONTFACE_CW						0x0900
#define GCM_FRONTFACE_CCW						0x0901

#define GCM_TYPE_POINTS							1			
#define GCM_TYPE_LINES							2			
#define GCM_TYPE_LINE_LOOP						3		
#define GCM_TYPE_LINE_STRIP						4		
#define GCM_TYPE_TRIANGLES						5		
#define GCM_TYPE_TRIANGLE_STRIP					6	
#define GCM_TYPE_TRIANGLE_FAN					7		
#define GCM_TYPE_QUADS							8			
#define GCM_TYPE_QUAD_STRIP						9		
#define GCM_TYPE_POLYGON						10			

#define GCM_INVALIDATE_TEXTURE					1
#define GCM_INVALIDATE_VERTEX_TEXTURE			2

#define GCM_TEXTURE_DIMS_1D						1
#define GCM_TEXTURE_DIMS_2D						2
#define GCM_TEXTURE_DIMS_3D						3

#define GCM_TEXTURE_FORMAT_SWZ					0x00
#define GCM_TEXTURE_FORMAT_LIN					0x20
#define GCM_TEXTURE_FORMAT_NRM					0x40

#define GCM_TEXTURE_FORMAT_L8					1
#define GCM_TEXTURE_FORMAT_A1R5G5B5				2
#define GCM_TEXTURE_FORMAT_A4R4G4B4				3
#define GCM_TEXTURE_FORMAT_R5G6B5				4
#define GCM_TEXTURE_FORMAT_A8R8G8B8				5
#define GCM_TEXTURE_FORMAT_DXT1					6
#define GCM_TEXTURE_FORMAT_DXT3					7
#define GCM_TEXTURE_FORMAT_DXT5					8
#define GCM_TEXTURE_FORMAT_A8L8					24

#define GCM_TEXTURE_REMAP_TYPE_B_SHIFT			14
#define GCM_TEXTURE_REMAP_TYPE_G_SHIFT			12
#define GCM_TEXTURE_REMAP_TYPE_R_SHIFT			10
#define GCM_TEXTURE_REMAP_TYPE_A_SHIFT			8

#define GCM_TEXTURE_REMAP_COLOR_B_SHIFT			6
#define GCM_TEXTURE_REMAP_COLOR_G_SHIFT			4
#define GCM_TEXTURE_REMAP_COLOR_R_SHIFT			2
#define GCM_TEXTURE_REMAP_COLOR_A_SHIFT			0

#define GCM_TEXTURE_REMAP_TYPE_ZERO				0
#define GCM_TEXTURE_REMAP_TYPE_ONE				1
#define GCM_TEXTURE_REMAP_TYPE_REMAP			2

#define GCM_TEXTURE_REMAP_COLOR_A				0
#define GCM_TEXTURE_REMAP_COLOR_R				1
#define GCM_TEXTURE_REMAP_COLOR_G				2
#define GCM_TEXTURE_REMAP_COLOR_B				3

#define GCM_TEXTURE_MAX_ANISO_1					0
#define GCM_TEXTURE_MAX_ANISO_2					1
#define GCM_TEXTURE_MAX_ANISO_4					2
#define GCM_TEXTURE_MAX_ANISO_6					3
#define GCM_TEXTURE_MAX_ANISO_8					4
#define GCM_TEXTURE_MAX_ANISO_10				5
#define GCM_TEXTURE_MAX_ANISO_12				6
#define GCM_TEXTURE_MAX_ANISO_16				7

#define GCM_TEXTURE_NEAREST						1
#define GCM_TEXTURE_LINEAR						2
#define GCM_TEXTURE_NEAREST_MIPMAP_NEAREST		3
#define GCM_TEXTURE_LINEAR_MIPMAP_NEAREST		4
#define GCM_TEXTURE_NEAREST_MIPMAP_LINEAR		5
#define GCM_TEXTURE_LINEAR_MIPMAP_LINEAR		6

#define GCM_TEXTURE_CONVOLUTION_QUINCUNX		1
#define GCM_TEXTURE_CONVOLUTION_GAUSSIAN		2
#define GCM_TEXTURE_CONVOLUTION_QUINCUNX_ALT	3

#define GCM_TEXTURE_REPEAT						1
#define GCM_TEXTURE_MIRRORED_REPEAT				2
#define GCM_TEXTURE_CLAMP_TO_EDGE				3
#define GCM_TEXTURE_CLAMP_TO_BORDER				4
#define GCM_TEXTURE_CLAMP						5
#define GCM_TEXTURE_MIRROR_CLAMP_TO_EDGE		6
#define GCM_TEXTURE_MIRROR_CLAMP_TO_BORDER		7
#define GCM_TEXTURE_MIRROR_CLAMP				8

#define GCM_TEXTURE_ZFUNC_NEVER					0
#define GCM_TEXTURE_ZFUNC_LESS					1
#define GCM_TEXTURE_ZFUNC_EQUAL					2
#define GCM_TEXTURE_ZFUNC_LEQUAL				3
#define GCM_TEXTURE_ZFUNC_GREATER				4
#define GCM_TEXTURE_ZFUNC_NOTEQUAL				5
#define GCM_TEXTURE_ZFUNC_GEQUAL				6
#define GCM_TEXTURE_ZFUNC_ALWAYS				7

#define GCM_VERTEX_ATTRIB_POS					0
#define GCM_VERTEX_ATTRIB_WEIGHT				1
#define GCM_VERTEX_ATTRIB_NORMAL				2
#define GCM_VERTEX_ATTRIB_COLOR0				3
#define GCM_VERTEX_ATTRIB_COLOR1				4
#define GCM_VERTEX_ATTRIB_FOG					5
#define GCM_VERTEX_ATTRIB_COLOR_INDEX			6
#define GCM_VERTEX_ATTRIB_POINT_SIZE			6	/*alias*/
#define GCM_VERTEX_ATTRIB_EDGEFLAG				7
#define GCM_VERTEX_ATTRIB_TEX0					8
#define GCM_VERTEX_ATTRIB_TEX1					9
#define GCM_VERTEX_ATTRIB_TEX2					10
#define GCM_VERTEX_ATTRIB_TEX3					11
#define GCM_VERTEX_ATTRIB_TEX4					12
#define GCM_VERTEX_ATTRIB_TEX5					13
#define GCM_VERTEX_ATTRIB_TEX6					14
#define GCM_VERTEX_ATTRIB_TEX7					15

#define GCM_VERTEX_DATA_TYPE_F32				2
#define GCM_VERTEX_DATA_TYPE_U8					4

#define GCM_INDEX_TYPE_32B						0
#define GCM_INDEX_TYPE_16B						1

#define GCM_USER_CLIP_PLANE_DISABLE				0
#define GCM_USER_CLIP_PLANE_LT					1
#define GCM_USER_CLIP_PLANE_GE					2

#define GCM_TRANSFER_SURFACE_FMT_R5G5B5			4
#define GCM_TRANSFER_SURFACE_FMT_A8R8G8B8		0xa
#define GCM_TRANSFER_SURFACE_FMT_Y32			0xb

#define GCM_SHADE_MODEL_FLAT					0x1D00
#define GCM_SHADE_MODEL_SMOOTH					0x1D01

#define GCM_ZERO								0
#define GCM_ONE									1
#define GCM_SRC_COLOR							0x0300
#define GCM_ONE_MINUS_SRC_COLOR					0x0301
#define GCM_SRC_ALPHA							0x0302
#define GCM_ONE_MINUS_SRC_ALPHA					0x0303
#define GCM_DST_ALPHA							0x0304
#define GCM_ONE_MINUS_DST_ALPHA					0x0305
#define GCM_DST_COLOR							0x0306
#define GCM_ONE_MINUS_DST_COLOR					0x0307
#define GCM_SRC_ALPHA_SATURATE					0x0308
#define GCM_CONSTANT_COLOR						0x8001
#define GCM_ONE_MINUS_CONSTANT_COLOR			0x8002
#define GCM_CONSTANT_ALPHA						0x8003
#define GCM_ONE_MINUS_CONSTANT_ALPHA			0x8004

#define GCM_FUNC_ADD							0x8006
#define GCM_MIN									0x8007
#define GCM_MAX									0x8008
#define GCM_FUNC_SUBTRACT						0x800a
#define GCM_FUNC_REVERSE_SUBTRACT				0x800b
#define GCM_FUNC_REVERSE_SUBTRACT_SIGNED		0xf005
#define GCM_FUNC_ADD_SIGNED						0xf006
#define GCM_FUNC_REVERSE_ADD_SIGNED				0xf007

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _gcmCtxData
{
	u32 begin;
	u32 end;
	u32 current;
	u32 callback;
} gcmContextData;

typedef struct _gcmCtrlRegister
{
	vu32 put;
	vu32 get;
	vu32 ref;
} gcmControlRegister;

typedef struct _gcmCfg
{
	u32 localAddress;
	u32 ioAddress;
	s32 localSize;
	s32 ioSize;
	s32 memoryFreq;
	s32 coreFreq;
} gcmConfiguration;


typedef struct _gcmSurface
{
	u8 type;
	u8 antiAlias;
	u8 colorFormat;
	u8 colorTarget;
	u8 colorLocation[GCM_MAX_MRT_COUNT];
	u32 colorOffset[GCM_MAX_MRT_COUNT];
	u32 colorPitch[GCM_MAX_MRT_COUNT];
	u8 depthFormat;
	u8 depthLocation;
	u8 _pad[2];
	u32 depthOffset;
	u32 depthPitch;
	u16 width;
	u16 height;
	u16 x;
	u16 y;
} gcmSurface;

typedef struct _gcmTexture
{
	u8 format;
	u8 mipmap;
	u8 dimension;
	u8 cubemap;
	u32 remap;
	u16 width;
	u16 height;
	u16 depth;
	u8 location;
	u8 _pad;
	u32 pitch;
	u32 offset;
} gcmTexture;

typedef s32 (*gcmContextCallback)(gcmContextData *context,u32 count);

s32 gcmInitBody(u32 *ctx,const u32 cmdSize,const u32 ioSize,const void *ioAddress);
s32 gcmAddressToOffset(u32 address,u32 *offset);
s32 gcmIoOffsetToAddress(u32 offset,u32 *address);
s32 gcmGetConfiguration(gcmConfiguration *config);
s32 gcmGetFlipStatus();
s32 gcmSetFlip(gcmContextData *context,u32 bufferId);
s32 gcmSetDisplayBuffer(u32 bufferId,u32 offset,u32 pitch,u32 width,u32 height);
s32 gcmMapMainMemory(const void *address,const u32 size,u32 *offset);
u32* gcmGetLabelAddress(const u8 index);
void gcmResetFlipStatus();
void gcmSetFlipMode(s32 mode);
void gcmSetWaitFlip(gcmContextData *context);
void gcmSetVBlankHandler(void (*handler)(const u32 head));
void gcmSetFlipHandler(void (*handler)(const u32 head));
void gcmSetGraphicsHandler(void (*handler)(const u32 val));
void gcmSetDefaultCommandBuffer();
gcmControlRegister* gcmGetControlRegister();

#ifdef __cplusplus
	}
#endif

#endif
