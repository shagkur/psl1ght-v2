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
	@[ -d $(PSL1GHT)/target/spu/include/vectormath ] || mkdir -p $(PSL1GHT)/target/spu/include/vectormath
	@cp -frv $(CURDIR)/c $(PSL1GHT)/target/spu/include/vectormath
	@cp -frv $(CURDIR)/cpp $(PSL1GHT)/target/spu/include/vectormath
	
clean:
	
.PHONY: all clean install
