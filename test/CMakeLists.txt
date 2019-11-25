cmake_minimum_required(VERSION 3.8)

include_directories(SYSTEM /usr/local/include)  # for boost etc
link_directories(/usr/local/lib) # for boost etc

add_executable(test_cpu test_cpu.cpp)
target_link_libraries(test_cpu boost_timer)
target_compile_options(test_cpu PRIVATE -O2 -Wall)
