#!/bin/sh
### BEGIN INIT INFO
# Provides:          mjpg-streamer
# Required-Start:    $local_fs $network $named $time $syslog
# Required-Stop:     $local_fs $network $named $time $syslog
# Default-Start:     2 3 4 5
# Default-Stop:      0 1 6
# Description:       Sensor Network Gateway
### END INIT INFO

NAME=mjpg-streamer
SCRIPT=/usr/sbin/run-mjpg-streamer.sh
#RUNAS=root

PIDFILE=/var/run/$NAME.pid

start() {
  if [ -f "$PIDFILE" ] && kill -0 $(cat "$PIDFILE"); then
    echo 'Service already running' >&2
    return 1
  fi
  echo 'Starting service.' >&2
#  local CMD="$SCRIPT & & echo \$!"
#  su -c "$CMD" $RUNAS > "$PIDFILE"
  $SCRIPT > /dev/null &
  echo $! > $PIDFILE
  echo 'Service started' >&2
}

stop() {
  if [ ! -f "$PIDFILE" ] || ! kill -0 $(cat "$PIDFILE"); then
    echo 'Service not running' >&2
    return 1
  fi
  echo 'Stopping service.' >&2
  kill -15 $(cat "$PIDFILE") && rm -f "$PIDFILE"
  echo 'Service stopped' >&2
}

case "$1" in
  start)
    start
    ;;
  stop)
    stop
    ;;
  uninstall)
    uninstall
    ;;
  retart)
    stop
    start
    ;;
  *)
    echo "Usage: $0 {start|stop|restart|uninstall}"
esac
