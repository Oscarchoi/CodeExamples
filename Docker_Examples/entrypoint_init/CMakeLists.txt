cmake_minimum_required(VERSION 3.10)

# set the project name
project(EntrypointInit)

# add the executable
add_executable(init my_init.cc)
add_executable(double_fork double_fork.cc)