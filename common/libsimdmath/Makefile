ifeq ($(strip $(PSL1GHT)),)
$(error "Please set PSL1GHT in your environment. export PSL1GHT=<path>")
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
