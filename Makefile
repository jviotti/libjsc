CMAKE = cmake
RMRF = rm -rf
PRESET = Debug

all: configure build

# TODO: Cannot disable: -DENABLE_API_TESTS=OFF
# See vendor/webkit/Source/cmake/OptionsJSCOnly.cmake
configure: .always
	CC=clang CXX=clang++ \
		$(CMAKE) -S vendor/webkit -B ./out \
			-DENABLE_FTL_JIT=ON \
			-DPORT="JSCOnly" \
			-DENABLE_TOOLS=OFF \
			-DCMAKE_BUILD_TYPE=$(PRESET) \
			-DENABLE_STATIC_JSC=ON \
			-DUSE_SYSTEM_MALLOC=ON \
			-G Ninja

build: .always
	PYTHONDONTWRITEBYTECODE=1 \
		$(CMAKE) --build ./out --config $(PRESET) --parallel

clean: .always
	$(RMRF) ./out

# For NMake, which doesn't support .PHONY
.always:
