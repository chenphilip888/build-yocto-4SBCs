DEFAULT_PREFERENCE = "1"

include u-boot-rockpi.inc

SRC_URI = " \
	git://github.com/u-boot/u-boot.git;branch=next; \
"
SRCREV = "${AUTOREV}"

S = "${WORKDIR}/git"

do_compile_append () {
	cp -a ${B}/tools/mkimage ${DEPLOY_DIR_IMAGE}
}
