#---------------------------------------------------------------------------------
# Clear the implicit built in rules
#---------------------------------------------------------------------------------
.SUFFIXES:
#---------------------------------------------------------------------------------
ifeq ($(strip $(PSL1GHT)),)
$(error "Please set PSL1GHT in your environment. export PSL1GHT=<path>")
endif

all:
	@make -C common --no-print-directory
	@make -C ppu --no-print-directory
	@make -C spu --no-print-directory
	@make -C tools --no-print-directory
	
install-ctrl:
	@[ -d $(PSL1GHT)/host ] || mkdir -p $(PSL1GHT)/host
	@cp -frv base_rules $(PSL1GHT)/host
	@cp -frv ppu_rules $(PSL1GHT)/host
	@cp -frv spu_rules $(PSL1GHT)/host

install-socat:
	@make -C tools install-socat --no-print-directory	
	
install:
	@make -C common install --no-print-directory
	@make -C ppu install --no-print-directory
	@make -C spu install --no-print-directory
	@make -C tools install --no-print-directory
	
clean:
	@make -C common clean --no-print-directory
	@make -C ppu clean --no-print-directory
	@make -C spu clean --no-print-directory
	@make -C tools clean --no-print-directory
	
.PHONY: all clean install
