DESCRIPTION = "Linux kernel for RockPi-4b"

require recipes-kernel/linux/linux-yocto.inc

DEPENDS += "openssl-native"

SRC_URI = " \
	git:///home/philip/build-yocto-4SBCs/rk3328/kernel.git;branch=master; \
"

SRCREV = "${AUTOREV}"
LINUX_VERSION = "4.4.154"

# Override local version in order to use the one generated by linux build system
# And not "yocto-standard"
LINUX_VERSION_EXTENSION = ""
PR = "r1"
PV = "${LINUX_VERSION}"

# Include only supported boards for now
COMPATIBLE_MACHINE = "(rk3036|rk3066|rk3288|rk3328|rk3399|rk3308)"
deltask kernel_configme

do_compile_append() {
	oe_runmake dtbs
}
