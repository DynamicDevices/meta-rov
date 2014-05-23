FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}:"

KERNEL_DEFCONFIG = "rov_defconfig"

SRC_URI += "file://rov_defconfig"

do_configure_prepend() {
	cp ${WORKDIR}/rov_defconfig ${S}/arch/arm/configs
}

