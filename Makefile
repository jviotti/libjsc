CMAKE = cmake
RMRF = rm -rf
PRESET = Debug

all: configure

configure: .always
	$(CMAKE) -S vendor/webkit -B ./out \
		-DENABLE_FTL_JIT=ON \
		-DPORT="JSCOnly" \
		-DCMAKE_BUILD_TYPE=$(PRESET) \
		-G Ninja

clean: .always
	$(RMRF) ./out

# For NMake, which doesn't support .PHONY
.always:
