
#!/bin/bash

rm -rf build

cmake -S . -B build \
  -DCMAKE_CXX_COMPILER=clang++ \
  -DCMAKE_C_COMPILER=clang \
  -DBUILD_TESTS=ON \
  -DCMAKE_CXX_FLAGS="-I/usr/include/c++/11 -I/usr/include/x86_64-linux-gnu/c++/11 -fprofile-instr-generate -fcoverage-mapping -Wno-error=conversion -Wno-error=float-conversion -Wno-error=sign-conversion -Wno-error=return-stack-address" \
  -DCMAKE_EXE_LINKER_FLAGS="-fprofile-instr-generate -L/usr/lib/gcc/x86_64-linux-gnu/11"

cmake --build build