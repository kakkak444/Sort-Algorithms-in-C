#!/usr/bin/bash

if [ $# -lt 1 ]; then
    echo "引数の数が足りません"
else
    gcc ./$1/$1.c -I"./" -o ./$1/a.out ${@:2} && ./$1/a.out
fi
