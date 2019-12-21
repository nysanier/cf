cmake_minimum_required(VERSION 3.8)

add_executable(cf_main cf_main.cpp)
target_link_libraries(cf_main)

add_subdirectory(problem)
add_subdirectory(contest)
