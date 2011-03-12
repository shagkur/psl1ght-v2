#---------------------------------------------------------------------------------
# Clear the implicit built in rules
#---------------------------------------------------------------------------------
.SUFFIXES:
#---------------------------------------------------------------------------------
ifeq ($(strip $(PSL1GHT)),)
$(error "Please set PSL1GHT in your environment. export PSL1GHT=<path>")
endif

all:
	@make -C libsputhread --no-print-directory
	
install-headers:
	@[ -d $(PSL1GHT)/spu ] || mkdir -p $(PSL1GHT)/spu
	@cp -frv include $(PSL1GHT)/spu
	
install: install-headers
	@make -C libsputhread install --no-print-directory
	
clean:
	@make -C libsputhread clean --no-print-directory
	
.PHONY: all clean install
