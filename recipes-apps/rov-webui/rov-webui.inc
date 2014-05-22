DESCRIPTION = "ROV WebUI server files"
HOMEPAGE = "https://www.assembla.com/spaces/urov"
LICENSE = "GPLv3"
LIC_FILES_CHKSUM = "file://rov/LICENSE;md5=4d7af0f1bdfa2e0c50324fbf5c544857"

FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}-${PV}:"

SRCBRANCH="master"
SRC_URI = "git://git.assembla.com/urov.rov-webui.git;protocol=ssh;user=git;branch=${SRCBRANCH}"

S = "${WORKDIR}/git"
SRCREV = "${AUTOREV}"

do_install () {
    install -d ${D}/usr/share/apache2/htdocs/rov
    cp -rpvf ${S}/rov/* ${D}/usr/share/apache2/htdocs/rov
}

FILES_${PN} = "/usr/share/apache2/htdocs/rov/*"

RDEPENDS_${PN} = "apache2"

