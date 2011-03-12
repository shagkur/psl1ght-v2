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
	@[ -d $(DEVKITPS3)/spu/include/vectormath ] || mkdir -p $(DEVKITPS3)/spu/include/vectormath
	@cp -frv $(CURDIR)/c $(DEVKITPS3)/spu/include/vectormath
	@cp -frv $(CURDIR)/cpp $(DEVKITPS3)/spu/include/vectormath
	
clean:
	
.PHONY: all clean install
