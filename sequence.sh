#!/bin/bash
# uploads an led sequence to arduino board

arduino --upload $SEQUENCES/*$1*/*.ino