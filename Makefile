CMAKE = cmake
RMRF = rm -rf
PRESET = Debug

all: configure

# TODO: Cannot disable: -DENABLE_API_TESTS=OFF
# See vendor/webkit/Source/cmake/OptionsJSCOnly.cmake
configure: .always
	$(CMAKE) -S vendor/webkit -B ./out \
		-DENABLE_FTL_JIT=ON \
		-DPORT="JSCOnly" \
		-DCMAKE_BUILD_TYPE=$(PRESET) \
		-DENABLE_STATIC_JSC=ON \
		-DUSE_SYSTEM_MALLOC=ON \
		-G Ninja

clean: .always
	$(RMRF) ./out

# For NMake, which doesn't support .PHONY
.always:
