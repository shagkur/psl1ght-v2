#---------------------------------------------------------------------------------
# Clear the implicit built in rules
#---------------------------------------------------------------------------------
.SUFFIXES:
#---------------------------------------------------------------------------------
ifeq ($(strip $(PSL1GHT)),)
$(error "Please set PSL1GHT in your environment. export PSL1GHT=<path>")
endif

all:
	@make -C crt --no-print-directory
	@make -C sprx --no-print-directory
	@make -C librt --no-print-directory
	@make -C librsx --no-print-directory
	
install-headers:
	@[ -d $(PSL1GHT)/ppu ] || mkdir -p $(PSL1GHT)/ppu
	@cp -frv include $(PSL1GHT)/ppu
	
install: install-headers
	@make -C crt install --no-print-directory
	@make -C sprx install --no-print-directory
	@make -C librt install --no-print-directory
	@make -C librsx install --no-print-directory
	
clean:
	@make -C crt clean --no-print-directory
	@make -C sprx clean --no-print-directory
	@make -C librt clean --no-print-directory
	@make -C librsx clean --no-print-directory
	
.PHONY: all clean install
