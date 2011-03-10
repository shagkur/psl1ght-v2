#include <stdio.h>
#include <stdlib.h>
#include <ppu-asm.h>

#include <sysutil/msg.h>
#include <sysutil/sysutil.h>

extern s32 sysUtilRegisterCallbackEx(s32 slot,opd32 *opd,void *usrdata);
extern s32 msgDialogOpenEx(msgType type,const char *msg,opd32 *func,void *usrData,void *unused);
extern s32 msgDialogOpen2Ex(msgType type,const char *msg,opd32 *func,void *usrData,void *unused);
extern s32 msgDialogOpenErrorCodeEx(u32 errorCode,opd32 *func,void *usrData,void *unused);

// sysUtil wrapper functions
s32 sysUtilRegisterCallback(s32 slot,sysutilCallback cb,void *usrdata)
{
	return sysUtilRegisterCallbackEx(slot,(opd32*)__get_opd32(cb),usrdata);
}

// msgDialog wraper functions
s32 msgDialogOpen(msgType type,const char *msg,msgDialogCallback cb,void *usrData,void *unused)
{
	return msgDialogOpenEx(type,msg,(opd32*)__get_opd32(cb),usrData,unused);
}

s32 msgDialogOpen2(msgType type,const char *msg,msgDialogCallback cb,void *usrData,void *unused)
{
	return msgDialogOpen2Ex(type,msg,(opd32*)__get_opd32(cb),usrData,unused);
}

s32 msgDialogOpenErrorCode(u32 errorCode,msgDialogCallback cb,void *usrData,void *unused)
{
	return msgDialogOpenErrorCodeEx(errorCode,(opd32*)__get_opd32(cb),usrData,unused);
}
