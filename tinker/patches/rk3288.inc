# Copyright (C) 2015 Romain Perier
# Released under the MIT license (see COPYING.MIT for the terms)

SOC_FAMILY = "rk3288"

require conf/machine/include/tune-cortexa17.inc
require conf/machine/include/soc-family.inc

MACHINEOVERRIDES =. "mali-gpu:mali-midgard:"

PREFERRED_PROVIDER_virtual/kernel = "linux-rockchip"
PREFERRED_VERSION_linux-rockchip = "4.4"

SERIAL_CONSOLES = "115200;ttyS2"
KERNEL_IMAGETYPE = "zImage"
KBUILD_DEFCONFIG = "miniarm-rk3288_defconfig"

# PREFERRED_PROVIDER_virtual/bootloader ?= "u-boot-rockchip"
# SPL_BINARY ?= "u-boot-spl-dtb.bin"

MACHINE_ESSENTIAL_EXTRA_RRECOMMENDS += " kernel-modules"
IMAGE_FSTYPES += "tinker-img"
IMAGE_CLASSES += "tinker-img"
