DESCRIPTION = "Streaming HTTP server for UVC webcam feeds"
HOMEPAGE = "http://mjpg-streamer.sourceforge.net/"
DEPENDS = "jpeg"
LICENSE = "GPLv2"
LIC_FILES_CHKSUM = "file://LICENSE;md5=751419260aa954499f7abaabaa882bbe"

FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}-${PV}:"

SRC_URI = " \
    svn://mjpg-streamer.svn.sourceforge.net/svnroot/mjpg-streamer;module=mjpg-streamer;protocol=https \
    file://makefile.patch \
    file://${PN}.sh \
    file://run-${PN}.sh \
"

inherit update-rc.d

INITSCRIPT_NAME = "${PN}.sh"
INITSCRIPT_PARAMS = "start 99 2 3 4 5 . stop 20 0 1 6 ."

S = "${WORKDIR}/mjpg-streamer"
SRCREV = "HEAD"

do_install () {
    echo "WORKDIR = ${WORKDIR}"
    echo "SOURCEDIR = ${S}"
    install -d ${D}${bindir}/
    install -m 0755 ${S}/mjpg_streamer ${D}${bindir}/
    install -m 0755 ${S}/input_uvc.so ${D}${bindir}/
    install -m 0755 ${S}/input_testpicture.so ${D}${bindir}/
    install -m 0755 ${S}/output_http.so ${D}${bindir}/
    install -d ${D}/var/
    install -d ${D}/var/www/

    cp -rpvf ${S}/www/* ${D}/var/www

    install -d ${D}${sbindir}/
    install -m 0755 ${WORKDIR}/run-${PN}.sh ${D}${sbindir}/run-${PN}.sh

    install -d ${D}${sysconfdir}/init.d
    install -m 0755 ${WORKDIR}/${PN}.sh ${D}${sysconfdir}/init.d/${PN}.sh
}

FILES_${PN}-www = "/var/www/*"

PACKAGES += " ${PN}-www"

