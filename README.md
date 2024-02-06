# ds_alg

My implementations of data structures and algorithms in C++.

## Build and run tests

Build:
```console
cmake -S . -B build && cmake --build build 
```

Run tests:
```console
GTEST_COLOR=1 ctest --test-dir build/ --output-on-failure
```