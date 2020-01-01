cmake_minimum_required(VERSION 3.8)

add_executable(lg_main lg_main.cpp)

# 试炼场
add_subdirectory(newbie)  # 新手村

# 月赛, LGR-066 2020-1
add_subdirectory(r66)
