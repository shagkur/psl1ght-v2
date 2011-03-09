#---------------------------------------------------------------------------------
# Clear the implicit built in rules
#---------------------------------------------------------------------------------
.SUFFIXES:
#---------------------------------------------------------------------------------
ifeq ($(strip $(PSL1GHT)),)
$(error "Please set PSL1GHT in your environment. export PSL1GHT=<path>")
endif

all:
	@make -C libsimdmath --no-print-directory
	@make -C vectormath --no-print-directory
	
install:
	@make -C libsimdmath install --no-print-directory
	@make -C vectormath install --no-print-directory
	
clean:
	@make -C libsimdmath clean --no-print-directory
	@make -C vectormath clean --no-print-directory
	
.PHONY: all clean install
