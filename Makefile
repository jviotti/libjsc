CMAKE = cmake
PRESET = Release

CC = clang
CXX = clang++

# See https://stackoverflow.com/a/30906085 \
!ifndef 0 # \
GENERATOR = Visual Studio 17 2022 # \
!else
GENERATOR = Ninja
# \
!endif

all: configure build test

configure: .always
	$(CMAKE) -S . -B ./out -DCMAKE_BUILD_TYPE=$(PRESET) -G "$(GENERATOR)"

build: .always
	PYTHONDONTWRITEBYTECODE=1 \
		$(CMAKE) --build ./out --config $(PRESET) --parallel

test: .always
	exec ./out/jsc_test

clean: .always
	$(CMAKE) -E rm -rf ./out

# For NMake, which doesn't support .PHONY
.always:
