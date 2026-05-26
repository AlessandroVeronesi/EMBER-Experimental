#!/bin/bash

TEST_NAME=$1
TEST_EXECUTABLE="./build/tests/sanity/sysutils/em_time/${TEST_NAME}"

LLVM_PROFILE_FILE="${TEST_NAME}.profraw" \
"${TEST_EXECUTABLE}"

./tools/coverage/merge-profdata.sh \
"${TEST_NAME}.profraw" \
"${TEST_NAME}.profdata"

./tools/coverage/show-summary.sh \
"${TEST_EXECUTABLE}" \
"${TEST_NAME}.profdata"

./tools/coverage/generate-html.sh \
"${TEST_EXECUTABLE}" \
"${TEST_NAME}.profdata" \
coverage_report