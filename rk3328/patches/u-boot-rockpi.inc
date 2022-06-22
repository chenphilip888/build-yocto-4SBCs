require recipes-bsp/u-boot/u-boot.inc

DESCRIPTION = "RockPi U-Boot"
LICENSE = "GPLv2+"
LIC_FILES_CHKSUM = "file://Licenses/README;md5=2ca5f2c35c8cc335f0a19756634782f1"
COMPATIBLE_MACHINE = "(rk3036|rk3066|rk3188|rk3288|rk3328|rk3399|rk3308)"

DEPENDS = "dtc-native bc-native swig-native bison-native"

# u-boot will build native python module
inherit pythonnative

do_compile_prepend () {
	export STAGING_INCDIR=${STAGING_INCDIR_NATIVE};
	export STAGING_LIBDIR=${STAGING_LIBDIR_NATIVE};
}

do_compile_append () {
	# copy to default search path
	if [ ${SPL_BINARY} ]; then
		cp ${B}/spl/${SPL_BINARY} ${B}/
	fi
}
