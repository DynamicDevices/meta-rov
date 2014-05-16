#!/bin/sh

gst-launch\
  v4l2src !\
  ffmpegcolorspace !\
  video/x-raw-yuv,width=320,height=240,framerate=\(fraction\)30/1 !\
  queue !\
  videorate !\
  video/x-raw-yuv,framerate=10/1 !\
  jpegenc !\
  multipartmux !\
  tcpserversink host=192.168.0.21 port=1010 sync=false


