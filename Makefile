CMAKE = cmake
RMRF = rm -rf
PRESET = Debug

all: configure

configure: .always
	$(CMAKE) -S . -B ./out -DCMAKE_BUILD_TYPE=$(PRESET) -G Ninja -DPORT="GTK"

clean: .always
	$(RMRF) ./out

# For NMake, which doesn't support .PHONY
.always:
