SUMMARY = "RTSP Server for GStreamer"
DESCRIPTION = "Command and Control Server for Underwater ROV"
SECTION = "applications"
PRIORITY = "optional"
LICENSE = "GPLv2"
LIC_FILES_CHKSUM = "file://LICENSE;md5=8c16666ae6c159876a0ba63099614381"

DEPENDS = "gstreamer1.0 gstreamer1.0-rtsp-server gstreamer1.0-plugins-good"

SRCBRANCH = "master"
SRCFORK = "DynamicDevices"
SRC_URI = "git://github.com/${SRCFORK}/rtsp.git;protocol=git;branch=${SRCBRANCH}"

S = "${WORKDIR}/git"

inherit autotools

#inherit update-rc.d

#INITSCRIPT_PACKAGES = "${PN}"
#INITSCRIPT_NAME_${PN} = "rov-server.boot.sh"
#INITSCRIPT_PARAMS_${PN} = "defaults 20 80"

RDEPENDS_${PN} = "gstreamer1.0 gstreamer1.0-plugins-base-videotestsrc  gstreamer1.0-plugins-base-videoconvert \
                  gstreamer1.0-plugins-good-rtpmanager gstreamer1.0-plugins-good-udp \
"

