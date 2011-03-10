#---------------------------------------------------------------------------------
# Clear the implicit built in rules
#---------------------------------------------------------------------------------
.SUFFIXES:
#---------------------------------------------------------------------------------
ifeq ($(strip $(PSL1GHT)),)
$(error "Please set PSL1GHT in your environment. export PSL1GHT=<path>")
endif

CC	:=	gcc

CFLAGS	:=	-Wall -Wno-char-subscripts -O2 -s

ifneq (,$(findstring MINGW,$(shell uname -s)))
	exeext		:= .exe
endif

ifneq (,$(findstring CYGWIN,$(UNAME)))
	exeext		:= .exe
endif

ifneq (,$(findstring Darwin,$(shell uname -s)))
	SDK	:=	/Developer/SDKs/MacOSX10.4u.sdk
	CFLAGS += -mmacosx-version-min=10.4 -isysroot $(SDK) -Wl,-syslibroot,$(SDK) -arch i386 -arch ppc
endif

tools	:=	$(patsubst %.c,%$(exeext),$(wildcard *.c)) \
		$(patsubst %.cpp,%$(exeext),$(wildcard *.cpp))


all:	$(tools)

clean:
	@rm -f $(tools)

%$(exeext)	:: %.c
	$(CC) $< -o $@ $(CFLAGS)

%$(exeext)	:: %.cpp
	$(CXX) $< -o $@ $(CFLAGS)

install:
	@[ -d $(PSL1GHT)/host/bin ] || mkdir -p $(PSL1GHT)/host/bin
	@cp -frv $(CURDIR)/$(tools) $(PSL1GHT)/host/bin
