#!/bin/bash

if [ $# -ne 2 ]; then
    echo "Usage: $0 <executable> <profile.profdata>"
    exit 1
fi

llvm-cov report "$1" \
    -instr-profile="$2" \
    ember/* \
    saboteurs/* \
    tests/*