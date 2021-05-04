DEVICE=xilinx_zcu104_base_202020_1
HOST_ARCH=aarch64
TARGET=sw_emu

.PHONY: build
build:
	make -C project/ DEVICE=$(DEVICE) HOST_ARCH=$(HOST_ARCH) SYSROOT=$(SYSROOT) TARGET=$(TARGET) all

.PHONY: run
run:
	cd project/package.$(TARGET); ./launch_$(TARGET).sh

.PHONY: clean
clean:
	make -C project/ clean

.PHONY: cleanall
cleanall:
	make -C project/ cleanall
	rm -rf *.jou *.log project/.ipcache
