CMAKE_MINIMUM_REQUIRED (VERSION 3.10)

# 컴파일러 지정
SET(CMAKE_CXX_COMPILER "g++")
SET(CMAKE_CXX_FLAGS "-std=c++14")

# 프로젝트 지정
project(CMakeExample)

# 빌드 결과물 경로 지정
message("CMAKE_BINARY_DIR: ${CMAKE_BINARY_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/output/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/output/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/output/lib)

# 하위 디렉토리 추가
add_subdirectory(Default)