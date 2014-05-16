SECTION = "base/configuration"
DESCRIPTION = "ROV configuration files"
LICENSE = "GPLv2"
LIC_FILES_CHKSUM = "file://${WORKDIR}/LICENSE;md5=63e0b237cc327468f00ad5b679a0940b"

FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}-${PV}:"

SRC_URI = "file://LICENSE \
           file://configure-smart-channels.sh \
           file://gst-server.sh \
"

do_install() {
        mkdir -p ${D}${bindir}
        install -m 0755 ${WORKDIR}/configure-smart-channels.sh ${D}${bindir}
        install -m 0755 ${WORKDIR}/gst-server.sh ${D}${bindir}
}

pkg_postinst_${PN} () {
#!/bin/sh -e
configure-smart-channels.sh
}
