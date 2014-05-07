DESCRIPTION = "A console-only image that fully supports the target device \
hardware."

IMAGE_FEATURES += "splash ssh-server-dropbear"
IMAGE_INSTALL += "\
        lighttpd \
        sqlite3  \
	daq \
        dosfstools \
"

LICENSE = "MIT"

inherit core-image


