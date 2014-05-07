#!/bin/sh

SMART_HOST=http://packages.dynamicdevices.co.uk/yocto

smart channel --remove devel-all -y
smart channel --remove devel-armv6_vfp -y
smart channel --remove devel-raspberrypi -y

smart channel --add devel-all name=devel-all type=rpm-md baseurl=$SMART_HOST/all -y
smart channel --add devel-armv6_vfp name=devel-armv6_vfp type=rpm-md baseurl=$SMART_HOST/armv6_vfp -y
smart channel --add devel-raspberrypi name=devel-raspberrypi type=rpm-md baseurl=$SMART_HOST/raspberrypi -y

echo Updated Smart Channel List
echo
smart channel --list

