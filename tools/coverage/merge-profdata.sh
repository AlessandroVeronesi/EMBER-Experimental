#!/bin/bash

if [ $# -ne 2 ]; then
    echo "Usage: $0 <input.profraw> <output.profdata>"
    exit 1
fi

llvm-profdata merge -sparse "$1" -o "$2"