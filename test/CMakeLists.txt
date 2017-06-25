cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
project(library.test)

enable_language(C)
enable_language(CXX)

set(CMAKE_CXX_FLAGS         "-std=c++11 -Wall -Wno-unknown-pragmas -Wno-sign-compare -Woverloaded-virtual -Wwrite-strings -Wno-unused")
set(CMAKE_CXX_FLAGS_DEBUG   "-O0 -g3")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DTEST_GTEST=1")

include(../cpp/cpp.cmake)

aux_source_directory(src SRC_LIST)
include_directories(googletest/googletest/include)
add_executable(unit_tests googletest/googletest/src/gtest-all.cc googletest/googletest/src/gtest-main.cc ${SRC_LIST})
