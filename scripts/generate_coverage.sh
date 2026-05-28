#!/usr/bin/env bash
set -euo pipefail

BUILD_DIR="build"
PROFRAW_PATTERN="$BUILD_DIR/coverage-%p.profraw"
PROFDATA_FILE="$BUILD_DIR/coverage.profdata"
REPORT_DIR="$BUILD_DIR/coverage_report"

rm -f "$BUILD_DIR"/coverage-*.profraw "$PROFDATA_FILE"
rm -rf "$REPORT_DIR"

export LLVM_PROFILE_FILE="$(pwd)/$PROFRAW_PATTERN" 
ctest --test-dir "$BUILD_DIR" --output-on-failure

llvm-profdata merge -sparse "$BUILD_DIR"/coverage-*.profraw -o "$PROFDATA_FILE"

TEST_EXECUTABLES=$(find "$BUILD_DIR" -type f -executable | grep '_tests$' || true)

if [ -z "$TEST_EXECUTABLES" ]; then
    echo "No test executables found."
    exit 1
fi

OBJECT_ARGS=""
for exe in $TEST_EXECUTABLES; do
    OBJECT_ARGS="$OBJECT_ARGS -object $exe"
done

llvm-cov show \
    $OBJECT_ARGS \
    -instr-profile="$PROFDATA_FILE" \
    -format=html \
    -output-dir="$REPORT_DIR" \
    -ignore-filename-regex='third_party|tests|saboteurs|/usr/include|build/third_party|build/tests'

llvm-cov report \
    $OBJECT_ARGS \
    -instr-profile="$PROFDATA_FILE" \
    -ignore-filename-regex='third_party|tests|saboteurs|/usr/include|build/third_party|build/tests'
    
    

echo "Coverage HTML report generated in: $REPORT_DIR/index.html"