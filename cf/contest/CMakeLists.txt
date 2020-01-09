cmake_minimum_required(VERSION 3.8)

# round 周赛，以总分来排名，每题都有固定分，然后减去罚时分，得到这题的分数，然后计算总分
add_subdirectory(cf595)
add_subdirectory(cf600)
add_subdirectory(cf601)
add_subdirectory(cf602)
add_subdirectory(cf603)
add_subdirectory(cf604)
add_subdirectory(cf605)
add_subdirectory(cf606)
add_subdirectory(cf607)
add_subdirectory(cf608)
add_subdirectory(cf609)
add_subdirectory(cf610)

# 类似ACM/ICPC的机制，以题数+罚时来排名
add_subdirectory(edu76)
add_subdirectory(edu77)
add_subdirectory(edu78)
add_subdirectory(edu79)

# 区预赛
add_subdirectory(nerc2019)

# 特殊赛
add_subdirectory(hello2020)
