UNAME	:=	$(shell uname -s)

ifneq (,$(findstring MINGW,$(UNAME)))
	PLATFORM	:= win32
	COMPILER	:= --compiler=mingw32
	OS			:= win32
endif

all: pkgcrypt.so

pkgcrypt.so: crypt.c setup.py
	@`./find-python2` setup.py build_ext $(COMPILER)
	@cp build/lib.*/pkgcrypt.* .

clean:
	rm -rf build pkgcrypt.*

install:
	@cp -frv ICON0.PNG sfo.xml pkgcrypt.* $(PSL1GHT)/host/bin/
	@./install-scripts $(PSL1GHT)/host/bin/ fself.py Struct.py sfo.py pkg.py
