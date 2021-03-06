#---------------------------------------------------------------------------------
# Clear the implicit built in rules
#---------------------------------------------------------------------------------
.SUFFIXES:
#---------------------------------------------------------------------------------
ifeq ($(strip $(PSL1GHT)),)
$(error "Please set PSL1GHT in your environment. export PSL1GHT=<path>")
endif

include	$(PSL1GHT)/host/ppu_rules

BUILD		:=	build

#---------------------------------------------------------------------------------
ifeq ($(strip $(PLATFORM)),)
#---------------------------------------------------------------------------------
export BASEDIR		:= $(CURDIR)
export DEPS			:= $(BASEDIR)/deps

#---------------------------------------------------------------------------------
else
#---------------------------------------------------------------------------------

export DEPSDIR		:=	$(DEPS)/$(PLATFORM)

#---------------------------------------------------------------------------------
endif
#---------------------------------------------------------------------------------

#---------------------------------------------------------------------------------
LD			:=	$(PREFIX)ld

DEFINCS		:=	-I$(BASEDIR) -I$(BASEDIR)/../include
INCLUDES	:=	$(DEFINCS)

CFLAGS		:= -O2 -mcpu=cell -mregnames -Wall $(MACHDEP) $(INCLUDES) -Wa,-mcell
ASFLAGS		:=	$(MACHDEP) -mcpu=cell -mregnames -D__ASSEMBLY__ -Wa,-mcell $(INCLUDES)

#---------------------------------------------------------------------------------
VPATH :=	$(BASEDIR)

#---------------------------------------------------------------------------------
OBJS		:= \
			crt0.o crt1.o lv2-crti.o lv2-crtn.o lv2-sprx.o
			
all: ppu

#---------------------------------------------------------------------------------
ppu:
#---------------------------------------------------------------------------------
	@[ -d $(DEPS)/ppu ] || mkdir -p $(DEPS)/ppu
	@[ -d ppu ] || mkdir -p ppu
	@$(MAKE) PLATFORM=ppu crts -C ppu -f $(CURDIR)/Makefile

#---------------------------------------------------------------------------------
install:
#---------------------------------------------------------------------------------
	@cp -frv $(CURDIR)/ppu/lv2-*.o $(PSL1GHT)/host/ppu/ppu/lib
	@cp -frv $(CURDIR)/lv2.ld $(PSL1GHT)/host/ppu/ppu/lib
	
.PHONY: crts ppu install

#---------------------------------------------------------------------------------
crts: $(OBJS)
	  @$(LD) -r crt0.o crt1.o -o lv2-crt0.o
#---------------------------------------------------------------------------------

#---------------------------------------------------------------------------------
clean:
#---------------------------------------------------------------------------------
	rm -fr ppu
	rm -fr $(DEPS)

-include $(DEPSDIR)/*.d
