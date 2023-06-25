project(main)
CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

SET(CMAKE_CXX_STANDARD 11)

ADD_SUBDIRECTORY(googletest)

ADD_EXECUTABLE(test
    unit_test.cpp
)

ADD_EXECUTABLE(lab
    main.cpp
)

target_precompile_headers(test
    PUBLIC
    <gtest/gtest.h>
)

TARGET_LINK_LIBRARIES(test gtest)


