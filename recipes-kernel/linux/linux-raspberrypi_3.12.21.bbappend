FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}:"

#SRCREV = "b09a27249d61475e4423607f7632a5aa6e7b3a53"
#SRCREV = "7a9c740f124af8cc64bdb0d88c31502eee473d33"

#SRC_URI = "git://github.com/DynamicDevices/linux.git;protocol=git;branch=rpi-3.12.y \
#           file://sl030raspberrypii2ckernel.patch \
#          "

KERNEL_DEFCONFIG = "rov_defconfig"

SRC_URI += "file://rov_defconfig \
"

#	    file://w1-gpio-pin-config.patch \
#

do_configure_prepend() {
	cp ${WORKDIR}/rov_defconfig ${S}/arch/arm/configs
}

#module_autoload_${PN} += "w1-gpio bcm2835-v4l2" 
