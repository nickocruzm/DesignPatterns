project(main)
CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

SET(CMAKE_CXX_STANDARD 11)
SET(CMAKE_BUILD_TYPE Debug)

ADD_SUBDIRECTORY(googletest)

ADD_EXECUTABLE(calculator main.cpp)

ADD_EXECUTABLE(test unit_test.cpp)

target_precompile_headers(test
    PUBLIC
    <gtest/gtest.h>
)

TARGET_LINK_LIBRARIES(test gtest)