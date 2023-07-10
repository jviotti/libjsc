CMAKE = cmake
PRESET = Release

CC = clang
CXX = clang++

all: configure build test

# See vendor/webkit/Source/cmake/OptionsJSCOnly.cmake
configure: .always
	$(CMAKE) -S . -B ./out -DCMAKE_BUILD_TYPE=$(PRESET) -G Ninja

build: .always
	PYTHONDONTWRITEBYTECODE=1 \
		$(CMAKE) --build ./out --config $(PRESET) --parallel

test: .always
	exec ./out/jsc_test

clean: .always
	$(CMAKE) -E rm -rf ./out

# For NMake, which doesn't support .PHONY
.always:
