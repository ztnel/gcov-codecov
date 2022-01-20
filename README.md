# Gcov & Code Coverage Integration

[![ci](https://github.com/ztnel/gcov-codecov/actions/workflows/codecov.yaml/badge.svg)](https://github.com/ztnel/gcov-codecov/actions/workflows/codecov.yaml)
[![codecov](https://codecov.io/gh/ztnel/gcov-codecov/branch/master/graph/badge.svg?token=CZ6T2ADTS0)](https://codecov.io/gh/ztnel/gcov-codecov)

Modified: 2022-01

A sample repository for configuring C projects with `gcov` and `codecov`.

## Build
Cmake project build and configuration
```bash
mkdir build
cd build
cmake ..
```

## Run Tests & Coverage
```bash
# test
make test
# compute coverage
make gcov
# clean gcov artefacts
make scrub
```
