export ARCH=arm
export CROSS_COMPILE=/usr/local/gcc-linaro-7.3.1-2018.05-x86_64_arm-linux-gnueabihf/bin/arm-linux-gnueabihf-

u-boot: builduboot postbuilduboot

builduboot:
	cd debian_u-boot; \
	make clean; \
	make ARCH=arm tinker-rk3288_defconfig; \
	make all

postbuilduboot:
	cd debian_u-boot; \
	./tools/mkimage -n rk3288 -T rksd -d ./spl/u-boot-spl-dtb.bin u-boot.img; \
	cat ./u-boot.bin >> u-boot.img

get_kernel:
	cd debian_kernel.git; \
	cp ../kernelpatches/rk3288-miniarm.dts ./arch/arm/boot/dts/; \
	git init; \
	git add * ; \
	git commit -m "initial release"; \
	git status; \
	git remote add origin https://github.com/TinkerBoard/debian_kernel.git

apply_patches:
	cd poky/build; \
	rm -rf ../meta-rockchip/recipes-graphics; \
	rm -rf ../meta-rockchip/recipes-bsp/rk-binary; \
	rm -rf ../meta-rockchip/recipes-bsp/u-boot; \
	rm -rf ../meta-rockchip/recipes-multimedia/gstreamer-rockchip; \
	rm -rf ../meta-rockchip/recipes-multimedia/rockchip-aiq; \
	cp -r ../../patches/recipes-graphics ../meta-rockchip/; \
	cp ../../patches/rk3288.inc ../meta-rockchip/conf/machine/include/; \
	cp ../../patches/tinker-img.bbclass ../meta-rockchip/classes/; \
	cp ../../patches/linux-rockchip_4.4.bb ../meta-rockchip/recipes-kernel/linux/; \
	cp ../../patches/systemd_%.bbappend ../meta-rockchip-extra/recipes-core/systemd/; \
	cp ../../patches/rk-image-multimedia.bb ../meta-rockchip-extra/recipes-rk/images/; \
	cp ../../patches/rk-base.inc ../meta-rockchip-extra/conf/distro/include/; \
	cp ../../patches/tcmode-default.inc ../meta/conf/distro/include/; \
	cp ../../patches/bblayers.conf ./conf/; \
	cp ../../patches/local.conf ./conf/
