#ifndef __RSX_PROGRAM_H__
#define __RSX_PROGRAM_H__

#include <ppu-types.h>

#define PARAM_FLOAT				0
#define PARAM_FLOAT2			1
#define PARAM_FLOAT3			2
#define PARAM_FLOAT4			3
#define PARAM_FLOAT4x4			4
#define PARAM_SAMPLER1D			5
#define PARAM_SAMPLER2D			6
#define PARAM_SAMPLER3D			7
#define PARAM_SAMPLERCUBE		8
#define PARAM_SAMPLERRECT		9
#define PARAM_UNKNOWN			0xff

#ifdef __cplusplus
extern "C" {
#endif

typedef struct rsx_vp
{
	u16 magic;
	u16 num_attrib;
	u32 attrib_off;

	u32 input_mask;
	u32 output_mask;

	u16 const_start;
	u16 num_const;
	u32 const_off;

	u16 start_insn;
	u16 num_insn;
	u32 ucode_off;
} rsxVertexProgram;

typedef struct rsx_fp
{
	u16 magic;
	u16 num_attrib;
	u32 attrib_off;

	u32 num_regs;
	u32 fp_control;

	u16 texcoords;
	u16 texcoord2D;
	u16 texcoord3D;

	u16 _pad0;

	u16 num_const;
	u32 const_off;

	u16 num_insn;
	u32 ucode_off;
} rsxFragmentProgram;

typedef struct rsx_const
{
	u32 name_off;
	u32 index;
	u8 type;
	u8 is_internal;
	u8 count;

	u8 _pad0;
	
	union {
		u32 u;
		f32 f;
	} values[4];

} rsxProgramConst;

typedef struct rsx_co_table
{
	u32 num;
	u32 offset[];
} rsxConstOffsetTable;

typedef struct rsx_attrib
{
	u32 name_off;
	u32 index;
} rsxProgramAttrib;

void* rsxVertexProgramGetUCode(rsxVertexProgram *vp);
rsxProgramConst* rsxVertexProgramGetConsts(rsxVertexProgram *vp);
s32 rsxVertexProgramGetConst(rsxVertexProgram *vp,const char *name);
rsxProgramAttrib* rsxVertexProgramGetAttribs(rsxVertexProgram *vp);
s32 rsxVertexProgramGetAttrib(rsxVertexProgram *vp,const char *name);

void* rsxFragmentProgramGetUCode(rsxFragmentProgram *fp,u32 *size);
rsxProgramConst* rsxFragmentProgramGetConsts(rsxFragmentProgram *fp);
s32 rsxFragmentProgramGetConst(rsxFragmentProgram *fp,const char *name);
rsxProgramAttrib* rsxFragmentProgramGetAttribs(rsxFragmentProgram *fp);
s32 rsxFragmentProgramGetAttrib(rsxFragmentProgram *fp,const char *name);

rsxConstOffsetTable* rsxFragmentProgramGetConstOffsetTable(rsxFragmentProgram *fp,u32 table_off);

#ifdef __cplusplus
	}
#endif

#endif
