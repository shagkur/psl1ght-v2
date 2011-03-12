#---------------------------------------------------------------------------------
# Clear the implicit built in rules
#---------------------------------------------------------------------------------
.SUFFIXES:
#---------------------------------------------------------------------------------
ifeq ($(strip $(DEVKITPS3)),)
$(error "Please set DEVKITPS3 in your environment. export DEVKITPS3=<path>")
endif

all:
	
install:
	@make -C ppu install --no-print-directory
	@make -C spu install --no-print-directory
	
clean:
	
.PHONY: all clean install
