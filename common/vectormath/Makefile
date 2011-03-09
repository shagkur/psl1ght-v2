#---------------------------------------------------------------------------------
# Clear the implicit built in rules
#---------------------------------------------------------------------------------
.SUFFIXES:
#---------------------------------------------------------------------------------
ifeq ($(strip $(PSL1GHT)),)
$(error "Please set PSL1GHT in your environment. export PSL1GHT=<path>")
endif

all:
	
install:
	@make -C ppu install --no-print-directory
	@make -C spu install --no-print-directory
	
clean:
	
.PHONY: all clean install
