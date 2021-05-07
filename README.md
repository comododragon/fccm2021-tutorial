# fccm2021-tutorial

FCCM 2021 Tutorial: FPGA High-Level Synthesis: Good Practices for Quality and Productivity

# Introduction

This is the GIT repository for the tutorial "FPGA High-Level Synthesis: Good Practices for Quality and Productivity", presented at the "The 29th IEEE International Symposium On Field-Programmable Custom Computing Machines".

Included here are several examples of High-Level Synthesis codes targetting a Xilinx ZCU104 FPGA platform. The toolchain version used is Xilinx Vitis 2020.2.

# Authors

* Andre Bannwart Perina
* Leandro Rosa
* Vanderlei Bonato

# Licence

Apache-2.0 is the licence used for this repository. See the ```LICENSE``` files for more details.

The code skeleton used for each project -- including the supporting files at ```common/includes```, the inner Makefiles, etc. --- were based on the Hello World example of the "Vitis Accel Examples Repository" (see https://github.com/Xilinx/Vitis_Accel_Examples/tree/master/hello_world ). These files are also licensed under Apache-2.0.

# Installation

A Xilinx Vitis 2020.2 installation with some additional packages is required. Please refer to the ```gettingstarted.pdf``` file for a guide on how to install these tools.

# Usage

1. Run the ```setup.sh``` to initialise environment variables related to Vitis:
    ```
    $ source ./setup.sh
    ```
    this must be performed only once per shell session.
2. CD to the example that you want to run, for example ```01-hello-world```:
    ```
    $ cd 01-hello-world
    ```
3. Run ```make``` to build the project:
     ```
    $ make build TARGET=<TARGET>
    ```
    where ```<TARGET>``` may be **hw** for hardware synthesis, **hw_emu** for hardware emulation and **sw_emu** for software emulation.
    For **hw_emu** and **sw_emu**, please skip step 4.
    For **hw**, please skip step 5 and 9.
4. If you selected **hw** as the target, the generated SD card image at ```01-hello-world/project/package.hw/sd_card.img``` must be cloned to a microSD card and booted on a ZCU104 platform. For other targets you can skip this step;
5. If you selected **hw_emu** or **sw_emu**, you can run QEMU to boot the SD image through an emulator:
    ```
    $ make run TARGET=<TARGET>
    ```
5. After the Linux system finishes to boot, CD to the SD card partition containing the hello world:
    ```
    $ cd /mnt/sd-mmcblk0p1
    ```
6. Run the initialisation script:
    ```
    $ source ./init.sh
    ```
7. Finally run the application:
    ```
    $ ./run_app.sh
    ```
8. A message saying ```TEST_PASSED``` should appear on your screen;
9. You can quit the emulation by pressing ```CTRL``` + ```A``` and then ```X```. For those who prefer to perform a safe shutdown, you can run ```poweroff``` prior to killing the emulator.

# Description of the Examples

* ```01-hello-world```: simple vector add (pipeline disabled)
* ```02-hello-world-auto-pipe```: simple vector add (pipeline automatically enabled)
* ```03-pipe-loop-carried-dep```: an example of a loop with carried dependency that hurts the pipeline
* ```04-pipe-false-dep```: a naive histogram implementation with a loop carried dependency
* ```05-pipe-false-dep-solution1```: first attempt to solve the carried dependency on the histogram kernel through code rewrite
* ```06-pipe-false-dep-solution2```: second (and successful) attempt using a pragma to indicate false dependency
* ```07-hello-world-unroll```: hello world example with unroll enabled
* ```08-hello-world-unroll-noexitcond```: hello world example with unroll and no exit condition check
* ```09-hello-world-large-unroll```: hello world example with large unroll factor
* ```10-hello-world-unroll-and-pipe```: hello world example unroll and pipeline enabled
* ```11-dataflow-example```: example of code that could benefit from dataflow optimisation
* ```12-dataflow-example-implemented```: the example code from ```11-dataflow-example``` but with dataflow implemented
* ```13-hello-world-arbitrary-precision```: hello world example but using operands with arbitrary precision data type
* ```14-pipe-loop-carried-dep-solution```: a solution to the ```03-pipe-loop-carried-dep``` dependency problem using shift register
* ```15-stencil```: a naive stencil implementation
* ```16-stencil-buffered```: implementation of ```15-stencil``` but using a buffer as a sliding window
* ```17-stencil-buffered-partitioned```: same as ```16-stencil-buffered```, but the buffer is completely partitioned
