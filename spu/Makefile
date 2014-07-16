#---------------------------------------------------------------------------------
# Clear the implicit built in rules
#---------------------------------------------------------------------------------
.SUFFIXES:
#---------------------------------------------------------------------------------
ifeq ($(strip $(DEVKITPS3)),)
$(error "Please set DEVKITPS3 in your environment. export DEVKITPS3=<path>")
endif

all:
	@make -C libsputhread --no-print-directory
	
install-headers:
	@[ -d $(DEVKITPS3)/spu ] || mkdir -p $(DEVKITPS3)/spu
	@cp -frv include $(DEVKITPS3)/spu
	
install: install-headers
	@make -C libsputhread install --no-print-directory
	
clean:
	@make -C libsputhread clean --no-print-directory
	
.PHONY: all clean install
