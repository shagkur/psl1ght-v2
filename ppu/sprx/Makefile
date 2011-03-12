ifeq ($(strip $(DEVKITPS3)),)
$(error "Please set DEVKITPS3 in your environment. export DEVKITPS3=<path>")
endif

all:
	@make -C libio --no-print-directory
	@make -C liblv2 --no-print-directory
	@make -C liblv2dbg --no-print-directory
	@make -C libnet --no-print-directory
	@make -C libgem --no-print-directory
	@make -C libaudio --no-print-directory
	@make -C libpngdec --no-print-directory
	@make -C libjpgdec --no-print-directory
	@make -C libgcm_sys --no-print-directory
	@make -C libsysfs --no-print-directory
	@make -C libsysutil --no-print-directory
	@make -C libsysmodule --no-print-directory
	
install:
	@make -C libio install --no-print-directory
	@make -C liblv2 install --no-print-directory
	@make -C liblv2dbg install --no-print-directory
	@make -C libnet install --no-print-directory
	@make -C libgem install --no-print-directory
	@make -C libaudio install --no-print-directory
	@make -C libpngdec install --no-print-directory
	@make -C libjpgdec install --no-print-directory
	@make -C libgcm_sys install --no-print-directory
	@make -C libsysfs install --no-print-directory
	@make -C libsysutil install --no-print-directory
	@make -C libsysmodule install --no-print-directory
	
clean:
	@make -C libio clean --no-print-directory
	@make -C liblv2 clean --no-print-directory
	@make -C liblv2dbg clean --no-print-directory
	@make -C libnet clean --no-print-directory
	@make -C libgem clean --no-print-directory
	@make -C libaudio clean --no-print-directory
	@make -C libpngdec clean --no-print-directory
	@make -C libjpgdec clean --no-print-directory
	@make -C libgcm_sys clean --no-print-directory
	@make -C libsysfs clean --no-print-directory
	@make -C libsysutil clean --no-print-directory
	@make -C libsysmodule clean --no-print-directory
	
.PHONY: all clean install
