DESCRIPTION = "ROV WebUI server files"
HOMEPAGE = "https://www.assembla.com/spaces/urov"
DEPENDS = "mjpg-streamer"
LICENSE = "GPLv3"
LIC_FILES_CHKSUM = "file://LICENSE;md5=4d7af0f1bdfa2e0c50324fbf5c544857"

FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}-${PV}:"

SRCBRANCH="master"
SRC_URI = "git://git.assembla.com/urov.rov-webui.git;protocol=ssh;user=git;branch=${SRCBRANCH}"

S = "${WORKDIR}/git"
SRCREV = "${AUTOREV}"

do_install () {
    install -d ${D}/var/www/
    cp -rpvf ${S}/* ${D}/var/www
}

FILES_${PN}-www = "/var/www/*"

