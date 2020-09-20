cmake_minimum_required(VERSION 3.10)

# set the project name
project(MinimalImage)

# set static complie flag
set (CMAKE_CXX_FLAGS "-static")

# add the executable
add_executable(hello hello.cc)
