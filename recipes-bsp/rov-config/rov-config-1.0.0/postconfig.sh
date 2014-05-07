#!/bin/sh

if ! test -e /etc/.configured_synced; then
        > /etc/.configured_synced
        echo Configured - synchronising filesystem
        sync
fi

