cmake_minimum_required(VERSION 3.5)
project(gcov-codecov C)

# set compiler options
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "-g -O0 -Wall -fprofile-arcs -ftest-coverage")
# stop cmake from including extension in .gnco file resolution for gcov
set(CMAKE_C_OUTPUT_EXTENSION_REPLACE 1)

# set artefacts path
set(ARTEFACT_DIR ${CMAKE_BINARY_DIR}/CMakeFiles/gcov-test.dir/lib)
message("-- Artefacts will be written to: ${ARTEFACT_DIR}")

# set sources
set(SOURCES test.c lib/lib.c)

# create executable
add_executable(gcov-test ${SOURCES})

# create gcov target and run coverage with make
add_custom_target(gcov
    COMMAND mkdir -p coverage
    COMMAND ${CMAKE_MAKE_PROGRAM} gcov-test
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR})
add_custom_command(TARGET gcov
    COMMAND echo "============= GCOV ============="
    COMMAND gcov -abcfu ${CMAKE_SOURCE_DIR}/lib/*.c -o ${ARTEFACT_DIR} > CoverageSummary.tmp
    COMMAND cat CoverageSummary.tmp
    COMMAND echo "-- Coverage files have been output to ${CMAKE_BINARY_DIR}/coverage"
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/coverage)
add_dependencies(gcov gcov-test)
# cleanup coverage folder
set_property(DIRECTORY APPEND PROPERTY ADDITIONAL_MAKE_CLEAN_FILES coverage)

# create gcov clean target. This cleans build and generated .gcno and .gcda aretefacts
add_custom_target(scrub
    COMMAND ${CMAKE_MAKE_PROGRAM} clean
    COMMAND rm -f ${ARTEFACT_DIR}/*.gcno
    COMMAND rm -f ${ARTEFACT_DIR}/*.gcda
    COMMAND echo "-- Coverage artefacts have been removed from ${CMAKE_BINARY_DIR}/coverage"
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR})

# testing
enable_testing()
add_test(NAME runs COMMAND ${CMAKE_CURRENT_BINARY_DIR}/gcov-test)