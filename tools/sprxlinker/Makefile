#---------------------------------------------------------------------------------
# Clear the implicit built in rules
#---------------------------------------------------------------------------------
.SUFFIXES:
#---------------------------------------------------------------------------------
ifeq ($(strip $(DEVKITPS3)),)
$(error "Please set DEVKITPS3 in your environment. export DEVKITPS3=<path>")
endif

UNAME	:=	$(shell uname -s)

ifneq (,$(findstring MINGW,$(UNAME)))
	POSTFIX	:= .exe
endif

ifneq (,$(findstring CYGWIN,$(UNAME)))
	POSTFIX	:= .exe
endif

TARGET		:= sprxlinker$(POSTFIX)
SOURCE		:= .
INCLUDE		:= .

CFLAGS		:= -O2 -Wall --std=gnu99
LDFLAGS		:= -lelf

CC			:= gcc

CFILES		:= $(foreach dir,$(SOURCE),$(wildcard $(dir)/*.c))
INCLUDES	:= $(foreach dir,$(INCLUDE),-I$(dir))

all: $(TARGET)

install:
	@[ -d $(DEVKITPS3)/bin ] || mkdir -p $(DEVKITPS3)/bin
	@cp -frv $(TARGET) $(DEVKITPS3)/bin
	
clean:
	rm -rf $(TARGET)
	
$(TARGET):	$(CFILES)
			@echo building ... $(notdir $@)
			@$(CC) $(CFLAGS) $(INCLUDES) $< -o $@ $(LDFLAGS)
			