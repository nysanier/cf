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
add_compile_options(-Wno-sign-compare)  # int和size_t比较
add_compile_options(-Wno-char-subscripts)  # char作为数组索引

add_subdirectory(at)  # atcoder
add_subdirectory(cf)  # codeforces
add_subdirectory(lc)  # leetcode
add_subdirectory(lg)  # luogu
add_subdirectory(nc)  # nowcoder
add_subdirectory(test)
add_subdirectory(proj)
