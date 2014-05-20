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

DEPENDS = "mono pi-blaster"

SRCBRANCH = "master"
SRC_URI = "git://git.assembla.com/urov.rov-server.git;protocol=ssh;user=git;branch=${SRCBRANCH} \
	   file://rov-server.boot.sh \
"

S = "${WORKDIR}/git"

inherit update-rc.d

INITSCRIPT_PACKAGES = "${PN}"
INITSCRIPT_NAME_${PN} = "rov-server.boot.sh"
INITSCRIPT_PARAMS_${PN} = "defaults 20 80"

CONFIGURATION = "Debug"

do_compile() {
        xbuild /p:Configuration=${CONFIGURATION}
}

do_install() {
        mkdir -p ${D}${sbindir}
        mkdir -p ${D}${sysconfdir}/init.d
        mkdir -p ${D}${libdir}/${PN}
        mkdir -p ${D}${libdir}/${PN}/.debug

        install -m 0755 ${S}/ROVServer/bin/${CONFIGURATION}/*.mdb ${D}${libdir}/${PN}/.debug
        install -m 0755 ${S}/ROVServer/bin/${CONFIGURATION}/*.exe ${D}${libdir}/${PN}
        install -m 0755 ${S}/ROVServer/bin/${CONFIGURATION}/*.config ${D}${libdir}/${PN}
        install -m 0755 ${S}/ROVServer/bin/${CONFIGURATION}/*.dll ${D}${libdir}/${PN}

        install -m 0755 ${S}/script.in ${D}${sbindir}/${PN}
        sed -i "s|@MONO@|mono|g" ${D}${sbindir}/${PN}
        sed -i "s|@prefix@|/usr|g" ${D}${sbindir}/${PN}
        sed -i "s|@APP@|${PN}|g" ${D}${sbindir}/${PN}

        install -m 0755 ${WORKDIR}/${PN}.boot.sh ${D}${sysconfdir}/init.d/${PN}.boot.sh
}

FILES_${PN} = "${libdir}/${PN}/*.exe \
		${libdir}/${PN}/*.config \
		${libdir}/${PN}/*.dll \
		${sbindir}/${PN} \
		${sysconfdir}/init.d/${PN}.boot.sh \
"

FILES_${PN}-dbg += "${libdir}/${PN}/.debug/*"

