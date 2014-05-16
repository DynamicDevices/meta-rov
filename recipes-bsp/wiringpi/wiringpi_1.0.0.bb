DESCRIPTION = "A wiring-like library for the Raspberry Pi, written in C"
HOMEPAGE = "https://projects.drogon.net/raspberry-pi/wiringpi"
LICENSE = "LGPLv3"
LIC_FILES_CHKSUM = "file://COPYING.LESSER;md5=e6a600fd5e1d9cbde2d983680233ad02"

FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}-${PV}:"

DEPENDS = ""

SRC_URI = " \
	git://git.drogon.net/wiringPi;protocol=git;tag=25e4ec570b0a1915a38792eb2b9d75d295152c3d \
	file://fix-wiringpi-make.patch \
	"

PR = "r0"

S = "${WORKDIR}/git"

do_configure () {
}

# todo: Fix makefile to remove relocations in .text QA warning

do_compile () {
  cd ${S}/wiringPi
  make
  cd ${S}/gpio
  make
  cd ${S}/examples
  make
  cd ${S}
}

do_install () {
  install -d ${D}${libdir}
  cp ${S}/wiringPi/libwiringPi.so.1.0 ${D}${libdir}
  install -d ${D}${bindir}
  cp ${S}/gpio/gpio ${D}${bindir}
}

