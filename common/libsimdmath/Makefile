ifeq ($(strip $(DEVKITPS3)),)
$(error "Please set DEVKITPS3 in your environment. export DEVKITPS3=<path>")
endif

all:
	@make -C ppu --no-print-directory
	@make -C spu --no-print-directory
	
install:
	@make -C ppu install --no-print-directory
	@make -C spu install --no-print-directory
	
clean:
	@make -C ppu clean --no-print-directory
	@make -C spu clean --no-print-directory
	
.PHONY: all clean install
