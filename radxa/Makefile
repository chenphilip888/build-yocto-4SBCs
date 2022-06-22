apply_patches:
	cd poky/build; \
	cp -r ../../patches/meta-custom ../; \
	cp -r ../../patches/recipes-graphics ../meta-radxa/; \
	cp ../../patches/rockpi-4b-rk3399.conf ../meta-radxa/conf/machine/; \
	cp ../../patches/rockchip-radxa-gpt-img.bbclass ../meta-radxa/classes/; \
	cp ../../patches/u-boot-rockpi.inc ../meta-radxa/recipes-bsp/u-boot/; \
	cp ../../patches/u-boot-rockpi-4.bb ../meta-radxa/recipes-bsp/u-boot/; \
	cp ../../patches/tcmode-default.inc ../meta/conf/distro/include/; \
	cp ../../patches/bblayers.conf ./conf/; \
	cp ../../patches/local.conf ./conf/
