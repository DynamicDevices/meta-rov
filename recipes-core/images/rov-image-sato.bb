#
# UI based Image for ROV Development
#

require recipes-sato/images/core-image-sato.bb

IMAGE_FEATURES += "ssh-server-openssh package-management"

# TODO: Look at why virtual/libsdl doesn't work here
#
# TODO: Import these recipes from OpenEmbedded legacy (maybe?):
#
#		libsdl-gfx \
#		python-pygame \
#		python-inotify \
#		i2c-tools \
#
#
# NOTE: Seem to need mono-dev to put libPosixHelper.so ???

require networking-packages.inc

IMAGE_INSTALL += "\
	        kernel-modules \
		rpm \
		nano \
		strace \
		libsdl \
		libsdl-mixer \
		libsdl-ttf \
		libsdl-image \
		minicom \
		gdbserver \
                python-core \
		python-modules \
		python-pydoc \
		python-misc \
		python-distutils \
		python-audio \
		python-compression \
		lua5.1 \
		mono \
		mono-dev \
		mono-helloworld \
		devmem2 \
                monotools-server \
		i2c-tools \
		rov-config \
                mjpg-streamer \
		gst-plugins-base-tcp \
                gst-plugins-good-jpeg \
                gst-plugins-good-video4linux2 \
                gst-plugins-base-videorate \
                gst-plugins-good-multipart \
                gst-ffmpeg \
		rov-server \
		"

# Disable splash
SPLASH = ""

export IMAGE_BASENAME = "rov-image-sato"

# Image post-processing



