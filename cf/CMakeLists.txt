cmake_minimum_required(VERSION 3.8)

if(CMAKE_SYSTEM_NAME STREQUAL "Darwin")
    add_compile_options(-Wno-nullability-completeness)
endif()

add_subdirectory(dp1029)
add_subdirectory(dp1105)
