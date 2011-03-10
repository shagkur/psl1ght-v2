#ifndef __RSX_COMMANDS_H__
#define __RSX_COMMANDS_H__

#include <rsx/gcm_sys.h>
#include <rsx/rsx_program.h>

#ifdef __cplusplus
extern "C" {
#endif


void rsxSetFrontFace(gcmContextData *context,u32 dir);
void rsxSetCullFace(gcmContextData *context,u32 cull);
void rsxSetCullFaceEnable(gcmContextData *context,u32 enable);
void rsxSetDepthWriteEnable(gcmContextData *context,u32 enable);
void rsxDrawVertexEnd(gcmContextData *context);
void rsxSetShadeModel(gcmContextData *context,u32 shadeModel);
void rsxDrawVertexBegin(gcmContextData *context,u32 type);
void rsxDrawVertex2f(gcmContextData *context,u8 idx,f32 x,f32 y);
void rsxDrawVertex3f(gcmContextData *context,u8 idx,f32 x,f32 y,f32 z);
void rsxDrawVertex4f(gcmContextData *context,u8 idx,f32 x,f32 y,f32 z,f32 w);
void rsxSetScissor(gcmContextData *context,u16 x,u16 y,u16 w,u16 h);
void rsxSetDepthFunc(gcmContextData *context,u32 func);
void rsxSetDepthTestEnable(gcmContextData *context,u32 enable);
void rsxClearSurface(gcmContextData *context,u32 clear_mask);
void rsxSetClearDepthValue(gcmContextData *context,u32 value);
void rsxSetReturnCommand(gcmContextData *context);
void rsxSetCallCommand(gcmContextData *context,u32 offset);
void rsxSetJumpCommand(gcmContextData *context,u32 offset);
void rsxSetNopCommand(gcmContextData *context,u32 count);
void rsxSetClearColor(gcmContextData *context,u32 color);
void rsxSetColorMask(gcmContextData *context,u32 mask);
void rsxSetColorMaskMRT(gcmContextData *context,u32 mask);
void rsxSetSurface(gcmContextData *context,gcmSurface *surface);
void rsxSetReferenceCommand(gcmContextData *context,u32 ref_value);
void rsxSetWaitLabel(gcmContextData *context,u8 index,u32 value);
void rsxSetWriteCommandLabel(gcmContextData *context,u8 index,u32 value);
void rsxSetWriteBackendLabel(gcmContextData *context,u8 index,u32 value);
void rsxSetViewportClip(gcmContextData *context,u8 sel,u16 width,u16 height);
void rsxSetViewport(gcmContextData *context,u16 x,u16 y,u16 width,u16 height,f32 min,f32 max,const f32 scale[4],const f32 offset[4]);
void rsxInvalidateTextureCache(gcmContextData *context,u32 type);
void rsxLoadTexture(gcmContextData *context,u8 index,const gcmTexture *texture);
void rsxTextureControl(gcmContextData *context,u8 index,u32 enable,u16 minlod,u16 maxlod,u8 maxaniso);
void rsxTextureFilter(gcmContextData *context,u8 index,u8 min,u8 mag,u8 conv);
void rsxTextureWrapMode(gcmContextData *context,u8 index,u8 wraps,u8 wrapt,u8 wrapr,u8 unsignedRemap,u8 zfunc,u8 gamma);
void rsxLoadVertexProgram(gcmContextData *context,rsxVertexProgram *program,const void *ucode);
void rsxLoadFragmentProgramLocation(gcmContextData *context,rsxFragmentProgram *program,u32 offset,u32 location);
void rsxZControl(gcmContextData *context,u8 cullNearFar,u8 zClampEnable,u8 cullIgnoreW);
void rsxLoadVertexProgramBlock(gcmContextData *context,rsxVertexProgram *program,const void *ucode);
void rsxLoadVertexProgramParameterBlock(gcmContextData *context,u32 base_const,u32 const_cnt,const f32 *value); 
void rsxSetVertexProgramParameter(gcmContextData *context,rsxVertexProgram *program,s32 index,const f32 *value);
void rsxSetFragmentProgramParameter(gcmContextData *context,rsxFragmentProgram *program,s32 index,const f32 *value,u32 offset);
void rsxDrawVertexArray(gcmContextData *context,u32 type,u32 start,u32 count);
void rsxBindVertexArrayAttrib(gcmContextData *context,u8 attr,u32 offset,u8 stride,u8 elems,u8 dtype,u8 location);
void rsxDrawIndexArray(gcmContextData *context,u32 type,u32 offset,u32 count,u32 data_type,u32 location);
void rsxInlineTransfer(gcmContextData *context,const u32 dstOffset,const void *srcAddress,const u32 sizeInWords,const u8 location);
void rsxSetUserClipPlaneControl(gcmContextData *context,u32 plane0,u32 plane1,u32 plane2,u32 plane3,u32 plane4,u32 plane5);
void rsxSetBlendFunc(gcmContextData *context,u16 sfcolor,u16 dfcolor,u16 sfalpha,u16 dfalpha);
void rsxSetBlendEquation(gcmContextData *context,u16 color,u16 alpha);
void rsxSetBlendColor(gcmContextData *context,u16 color0,u16 color1);
void rsxSetBlendEnable(gcmContextData *context,u32 enable);

#ifdef __cplusplus
	}
#endif

#endif
