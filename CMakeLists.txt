cmake_minimum_required(VERSION 3.8)

project(cf)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_OSX_SYSROOT /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk)

if(CMAKE_SYSTEM_NAME STREQUAL "Darwin")
    add_compile_options(-Wno-nullability-completeness)
endif()

add_compile_options(-Wall)

add_subdirectory(cf)
add_subdirectory(at)
