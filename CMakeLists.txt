cmake_minimum_required (VERSION 2.8)
add_definitions(-std=c++11)

project(mergesort)

find_package (glog REQUIRED)
find_package (gflags REQUIRED)
find_package(benchmark REQUIRED)

aux_source_directory(src DIR_SRCS)

add_executable(merge-sort-benchmark ${DIR_SRCS})
target_link_libraries(merge-sort-benchmark glog)
target_link_libraries(merge-sort-benchmark gflags)
target_link_libraries(merge-sort-benchmark benchmark)