CMAKE_MINIMUM_REQUIRED (VERSION 3.10)

# 컴파일러 지정
SET(CMAKE_CXX_COMPILER "g++")
SET(CMAKE_CXX_FLAGS "-std=c++14")

# 프로젝트 지정
project(CMakeExample)

# 하위 디렉토리 추가
add_subdirectory(Default)