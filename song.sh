#!/bin/sh
# uploads a song led show to arduino board, tabs to youtube and begins song

arduino --upload $SONGS/*$1*/*.ino
wmctrl -a Google\ Chrome
xdotool key space
