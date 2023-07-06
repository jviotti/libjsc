CMAKE = cmake
RMRF = rm -rf
PRESET = Release

all: configure build test

# See vendor/webkit/Source/cmake/OptionsJSCOnly.cmake
configure: .always
	CC=clang CXX=clang++ \
		$(CMAKE) -S . -B ./out -DCMAKE_BUILD_TYPE=$(PRESET) -G Ninja

build: .always
	PYTHONDONTWRITEBYTECODE=1 \
		$(CMAKE) --build ./out --config $(PRESET) --parallel

test: .always
	exec ./out/jsc_test

clean: .always
	$(RMRF) ./out

# For NMake, which doesn't support .PHONY
.always:
