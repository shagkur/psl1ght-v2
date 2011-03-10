#ifndef __LV2_PAD_H__
#define __LV2_PAD_H__

#include <ppu-types.h>

#define MAX_PADS					(127)
#define MAX_PAD_CODES				(64)
#define MAX_PORT_NUM				(7)
#define MAX_PAD_CAPABILITY_INFO		(32)
#define MAX_PAD_ACTUATOR			(2)

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _pad_info
{
	u32 max;
	u32 connected;
	u32 info;
	u16 vendor_id[MAX_PADS];
	u16 product_id[MAX_PADS];
	u8 status[MAX_PADS];
} padInfo;

typedef struct _pad_info2
{
	u32 max; /* max pads allowed to connect */
	u32 connected; /* how many pads connected */
	u32 info; /* Bit 0 lets the system intercept pad? other bits are reserved */
    u32 port_status[MAX_PORT_NUM]; /* Bit 0: Connected (0: Disconnected, 1: Connected), Bit 1: assign changes? */
    u32 port_setting[MAX_PORT_NUM]; /* Bit 1: Pressure sensitivity turned on, Bit 2: Sensors turned on */
    u32 device_capability[MAX_PORT_NUM]; /* See: PadCapabilityInfo. Bit 0: PS3SPEC, Bit 1: has_pressure, Bit 2: has_sensor, Bit 3: has_hps, Bit 4: has_vibrate */
    u32 device_type[MAX_PORT_NUM]; /* 0: Standard, 4: Bluray Remote, 5: LDD */
} padInfo2;

typedef struct _pad_data
{
	s32 len;
	union{
		u16 button[MAX_PAD_CODES];
		struct {
			u16 zeroes;
			unsigned int : 8; /* reserved */
			unsigned int seven : 4; /* always 0x7 */
			unsigned int halflen : 4; /* len/2 */
			unsigned int : 8; /* reserved */
			/* Button information */
			/* 0: UP, 1: DOWN */
			unsigned int BTN_LEFT : 1;
			unsigned int BTN_DOWN : 1;
			unsigned int BTN_RIGHT : 1;
			unsigned int BTN_UP : 1;
			unsigned int BTN_START : 1;
			unsigned int BTN_R3 : 1;
			unsigned int BTN_L3 : 1;
			unsigned int BTN_SELECT : 1;

			unsigned int : 8; /* reserved */
			unsigned int BTN_SQUARE : 1;
			unsigned int BTN_CROSS : 1;
			unsigned int BTN_CIRCLE : 1;
			unsigned int BTN_TRIANGLE : 1;
			unsigned int BTN_R1 : 1;
			unsigned int BTN_L1 : 1;
			unsigned int BTN_R2 : 1;
			unsigned int BTN_L2 : 1;

			/* Analog nub information */
			/* 0x0000 - 0x00FF */
			unsigned int ANA_R_H : 16;
			unsigned int ANA_R_V : 16;
			unsigned int ANA_L_H : 16;
			unsigned int ANA_L_V : 16;

			/* Pressure-sensitive information */
			/* 0x0000 - 0x00FF */
			unsigned int PRE_RIGHT : 16;
			unsigned int PRE_LEFT : 16;
			unsigned int PRE_UP : 16;
			unsigned int PRE_DOWN : 16;
			unsigned int PRE_TRIANGLE : 16;
			unsigned int PRE_CIRCLE : 16;
			unsigned int PRE_CROSS : 16;
			unsigned int PRE_SQUARE : 16;
			unsigned int PRE_L1 : 16;
			unsigned int PRE_R1 : 16;
			unsigned int PRE_L2 : 16;
			unsigned int PRE_R2 : 16;

			/* Sensor information */
			/* 0x0000 - 0x03FF */
			unsigned int SENSOR_X : 16;
			unsigned int SENSOR_Y : 16;
			unsigned int SENSOR_Z : 16;
			unsigned int SENSOR_G : 16;
			u8 reserved[80]; /* reserved */
		};
	};
} padData;

typedef struct _pad_capability_info
{
	union {
		u32 info[MAX_PAD_CAPABILITY_INFO];
		struct {
			unsigned int ps3spec : 1; /* controller meets ps3 specifications */
			unsigned int has_pressure : 1; /* controller has pressure-sensitive buttons */
			unsigned int has_sensors : 1; /* controller has sensors, e.g. sixaxis, X,Y,Z,G */
			unsigned int has_hps : 1; /* controller has high precision stick */
			unsigned int has_vibrate : 1; /* controller has inbuilt vibration motor */
			unsigned int : 27; /* reserved */
			u32 reserved[MAX_PAD_CAPABILITY_INFO-1];
		};
	};
} padCapabilityInfo;

typedef struct _pad_act_param
{
	union {
		u8 motor[MAX_PAD_ACTUATOR];
		struct {
			/* Small Motor */
			/* 0: OFF, 1: On */
			u8 small_motor;
			/* Large Motor */
			/* 0: OFF, 1-255: Motor Speed, higher == faster. */
			u8 large_motor;
		};
	};
	u8 reserved[6];
} padActParam;

typedef struct _pad_periph_info
{
	u32 max; /* max pads allowed to connect */
	u32 connected; /* how many pads connected */
	u32 info; /* bit 0 lets the system intercept pad? other bits are reserved */
    u32 port_status[MAX_PORT_NUM]; /* Bit 0: Connected (0: Disconnected, 1: Connected), Bit 1: assign changes? */
    u32 port_setting[MAX_PORT_NUM]; /* Bit 1: Pressure sensitivity turned on, Bit 2: Sensors turned on */
    u32 device_capability[MAX_PORT_NUM]; /* See: PadCapabilityInfo. Bit 0: PS3SPEC, Bit 1: has_pressure, Bit 2: has_sensor, Bit 3: has_hps, Bit 4: has_vibrate */
    u32 device_type[MAX_PORT_NUM]; /* 0: Standard, 4: Bluray Remote, 5: LDD */
    u32 pclass_type[MAX_PORT_NUM];
    u32 pclass_profile[MAX_PORT_NUM];
} padPeriphInfo;

typedef struct _pad_periph_data
{
	u32 pclass_type;
	u32 pclass_profile;
	s32 len;
	u16 button[MAX_PAD_CODES];
} padPeriphData;

s32 ioPadInit(u32 max);
s32 ioPadEnd();
s32 ioPadGetInfo(padInfo* info);
s32 ioPadClearBuf(u32 port);
s32 ioPadGetCapabilityInfo(u32 port, padCapabilityInfo* capabilities);
s32 ioPadGetData(u32 port, padData* data);
s32 ioPadInfoPressMode(u32 port);
s32 ioPadSetPressMode(u32 port, u32 mode);
s32 ioPadInfoSensorMode(u32 port);
s32 ioPadSetSensorMode(u32 port, u32 mode);
u32 ioPadSetActDirect(u32 port, padActParam* actParam);
u32 ioPadLddDataInsert(s32 handle, padData* data);
s32 ioPadLddGetPortNo(s32 handle);
s32 ioPadLddRegisterController();
s32 ioPadLddUnregisterController(s32 handle);

/* new in 3.41 */
s32 ioPadGetInfo2(padInfo2* info);
s32 ioPadPeriphGetInfo(padPeriphInfo* periphInfo);
s32 ioPadPeriphGetData(u32 port, padPeriphData* periphData);
s32 ioPadSetPortSetting(u32 port, u32 setting);

#ifdef __cplusplus
	}
#endif

#endif
