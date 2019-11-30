cmake_minimum_required(VERSION 3.8)

add_executable(ut_main main.cpp)
target_link_libraries(ut_main)

add_executable(ut_union_find union_find.cpp)
add_executable(ut_pbds_tree pbds_tree.cpp)
