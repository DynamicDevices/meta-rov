#
# Image for ROV Development
#


require networking-packages.inc

require gstreamer1.0-packages.inc

require rpi-packages.inc

IMAGE_FEATURES += "ssh-server-openssh package-management"

#		lua5.1 \
#

IMAGE_INSTALL += "\
	        kernel-modules \
		\
		nano \
                mjpg-streamer \
		v4l-utils \
		\
		rov-server \
		rov-config \
		rov-webui \
		"

# Disable splash
SPLASH = ""

# Image post-processing



