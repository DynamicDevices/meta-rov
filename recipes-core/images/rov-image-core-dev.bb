#
# UI based Image for ROV Development
#

require recipes-core/images/core-image-base.bb

require rov-image-core.inc

IMAGE_FEATURES += "dev-pkgs"

export IMAGE_BASENAME = "rov-image-core-dev"



