#
# Core Console Image for ROV Development
#

require recipes-core/images/core-image-base.bb

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
		devmem2 \
		"

# Disable splash
SPLASH = ""

export IMAGE_BASENAME = "rov-image-core"

# Image post-processing



