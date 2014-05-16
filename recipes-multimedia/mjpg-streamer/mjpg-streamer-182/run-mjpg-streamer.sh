#!/bin/sh
mjpg_streamer -i "/usr/bin/input_uvc.so -r 640x480 -n -y" -o "/usr/bin/output_http.so -w /var/www"
