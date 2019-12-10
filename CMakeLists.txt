cmake_minimum_required(VERSION 3.8)

project(cf)

if(CMAKE_SYSTEM_NAME STREQUAL "Darwin")
    # brew install gcc@6
    set(CMAKE_C_COMPILER "/usr/local/bin/gcc-6")
    set(CMAKE_CXX_COMPILER "/usr/local/bin/g++-6")
endif()

# for windows
# install mingw-64, git, cmake
# config path for cmake git

set(CMAKE_CXX_STANDARD 14)
# set(CMAKE_CXX_STANDARD_REQUIRED ON)
# set(CMAKE_CXX_EXTENSIONS OFF)

add_compile_options(-Wall)
include_directories(SYSTEM include)  # for self/bits/stdc++.h, common c/c++ headers

add_subdirectory(cf)
add_subdirectory(at)
add_subdirectory(test)
add_subdirectory(ut)
