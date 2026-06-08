#!/bin/bash

if [ $# -ne 3 ]; then
    echo "Usage: $0 <executable> <profile.profdata> <output-dir>"
    exit 1
fi

llvm-cov show "$1" \
    -instr-profile="$2" \
    ember/* \
    saboteurs/* \
    tests/* \
    -format=html \
    -output-dir="$3"