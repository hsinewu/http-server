#!/bin/sh


start() {
    echo Starting http-server...
    /root/work/http-server/http &
}

stop() {
    echo Stoping http-server...
    pkill http
}

$1