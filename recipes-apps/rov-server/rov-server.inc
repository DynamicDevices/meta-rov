SUMMARY = "ROV Server"
DESCRIPTION = "Command and Control Server for Underwater ROV"
AUTHOR = "Alex J Lennon <ajlennon@dynamicdevices.co.uk>"
HOMEPAGE = "http://www.dynamicdevices.co.uk"
SECTION = "mono/applications"
PRIORITY = "optional"
LICENSE = "GPLv3 & MIT & Apache-2.0"
LIC_FILES_CHKSUM = "file://LICENSE.rovserver;md5=4d7af0f1bdfa2e0c50324fbf5c544857 \
                    file://LICENSE.log4net;md5=86d3f3a95c324c9479bd8986968f4327 \
                    file://COPYING.mono-upnp;md5=2b0fcb9ea37f23f59acc7163e7727d39 \
"

DEPENDS = "mono wiringpi"

SRCBRANCH = "master"
SRC_URI = "git://git.assembla.com/urov.rov-server.git;protocol=ssh;user=git;branch=${SRCBRANCH}"

S = "${WORKDIR}/git"

CONFIGURATION = "Debug"

do_compile() {
        xbuild /p:Configuration=${CONFIGURATION}
}

do_install() {
        mkdir -p ${D}${bindir}
        mkdir -p ${D}${libdir}/${PN}
        mkdir -p ${D}${libdir}/${PN}/.debug

        install -m 0755 ${S}/ROVServer/bin/${CONFIGURATION}/*.mdb ${D}${libdir}/${PN}/.debug
        install -m 0755 ${S}/ROVServer/bin/${CONFIGURATION}/*.exe ${D}${libdir}/${PN}
        install -m 0755 ${S}/ROVServer/bin/${CONFIGURATION}/*.dll ${D}${libdir}/${PN}

        install -m 0755 ${S}/script.in ${D}${bindir}/${PN}
        sed -i "s|@MONO@|mono|g" ${D}${bindir}/${PN}
        sed -i "s|@prefix@|/usr|g" ${D}${bindir}/${PN}
        sed -i "s|@APP@|${PN}|g" ${D}${bindir}/${PN}
}

FILES_${PN} = "${libdir}/${PN}/*.exe \
		${libdir}/${PN}/*.dll \
		${bindir}/${PN} \
"

FILES_${PN}-dbg += "${libdir}/${PN}/.debug/*"

