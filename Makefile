#---------------------------------------------------------------------------------
# Clear the implicit built in rules
#---------------------------------------------------------------------------------
.SUFFIXES:
#---------------------------------------------------------------------------------
ifeq ($(strip $(DEVKITPS3)),)
$(error "Please set DEVKITPS3 in your environment. export DEVKITPS3=<path>")
endif

all:
	@make -C common --no-print-directory
	@make -C ppu --no-print-directory
	@make -C spu --no-print-directory
	@make -C tools --no-print-directory
	
install-ctrl:
	@[ -d $(DEVKITPS3) ] || mkdir -p $(DEVKITPS3)
	@cp -frv base_rules $(DEVKITPS3)
	@cp -frv ppu_rules $(DEVKITPS3)
	@cp -frv spu_rules $(DEVKITPS3)

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
