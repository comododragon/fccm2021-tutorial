#!/bin/bash

source /data/opt/Xilinx/Vitis/2024.1/settings64.sh
source /data/opt/Xilinx/petalinux/2024.1/environment-setup-cortexa72-cortexa53-xilinx-linux
export PLATFORM_REPO_PATHS=/data/opt/Xilinx/Vitis/2024.1/base_platforms/xilinx_zcu104_base_202410_1
export EDGE_COMMON_SW=/data/opt/Xilinx/rootfs/2024.1/xilinx-zynqmp-common-v2024.1
export SYSROOT=/data/opt/Xilinx/petalinux/2024.1/sysroots/cortexa72-cortexa53-xilinx-linux