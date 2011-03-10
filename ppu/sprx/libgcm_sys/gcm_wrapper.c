#include <ppu-asm.h>
#include <rsx/gcm_sys.h>

extern void gcmSetVBlankHandlerEx(opd32 *opd);
extern void gcmSetFlipHandlerEx(opd32 *opd);
extern void gcmSetGraphicsHandlerEx(opd32 *opd);

void gcmSetVBlankHandler(void (*handler)(const u32 head))
{
	gcmSetVBlankHandlerEx((opd32*)__get_opd32(handler));
}

void gcmSetFlipHandler(void (*handler)(const u32 head))
{
	gcmSetFlipHandlerEx((opd32*)__get_opd32(handler));
}

void gcmSetGraphicsHandler(void (*handler)(const u32 val))
{
	gcmSetGraphicsHandlerEx((opd32*)__get_opd32(handler));
}
