cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
project(library.test)

enable_language(C)
enable_language(CXX)

set(CMAKE_CXX_FLAGS         "-std=c++11 -Wall -Wno-unknown-pragmas -Wno-sign-compare -Woverloaded-virtual -Wwrite-strings -Wno-unused")
set(CMAKE_CXX_FLAGS_DEBUG   "-O0 -g3")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DTEST_GTEST=1")

include(${CMAKE_SOURCE_DIR}/../cpp/cpp.cmake)

aux_source_directory(${CMAKE_SOURCE_DIR}/src SRC_LIST)

include_directories(${CMAKE_SOURCE_DIR}/googletest/googletest/include)
include_directories(${CMAKE_SOURCE_DIR}/googletest/googletest)
add_executable(${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/googletest/googletest/src/gtest-all.cc ${CMAKE_SOURCE_DIR}/googletest/googletest/src/gtest_main.cc ${SRC_LIST})
target_link_libraries(${PROJECT_NAME} pthread)

