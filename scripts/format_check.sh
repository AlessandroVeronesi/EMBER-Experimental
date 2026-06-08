#!/bin/bash

find ember tests \
    \( -name "*.cpp" -o -name "*.hpp" -o -name "*.tpp" \) \
    -exec clang-format --dry-run --Werror {} +






