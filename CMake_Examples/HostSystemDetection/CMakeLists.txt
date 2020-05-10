CMAKE_MINIMUM_REQUIRED (VERSION 3.10)

SET(CMAKE_CXX_COMPILER "g++")
SET(CMAKE_CXX_FLAGS "-std=c++14")

message("Host System Detection")

# 프로젝트 지정
project(HostSystemDetection)

# 호스트 시스템 타입 
message("Host system name : ${CMAKE_HOST_SYSTEM_NAME}")
message("Host system version : ${CMAKE_HOST_SYSTEM_VERSION}")
message("Host processor type :${CMAKE_HOST_SYSTEM_PROCESSOR}")
message("Host library architecture :${CMAKE_LIBRARY_ARCHITECTURE}")

# 포인터 크기 계산
math(EXPR ARCHITECTURE "8*${CMAKE_SIZEOF_VOID_P}")
if(ARCHITECTURE EQUAL 64)
  MESSAGE("Host system architecture: 64 bit")
endif()

# 호스트 시스템 정보 변경 - 가능
set(CMAKE_HOST_SYSTEM_VERSION "kkk")
MESSAGE("Modified Host system version : ${CMAKE_HOST_SYSTEM_VERSION}")

# 시스템 아키텍처 판별 분기
if(${CMAKE_HOST_SYSTEM_PROCESSOR} STREQUAL "x86_64")
  MESSAGE(FATAL_ERROR "***** Current system architecture is x86_64. *****")
endif()



# 빌드 타겟 소스 지정 및 추가
set(TARGET "foo")
set(SRC foo.cc)
add_executable(${TARGET} ${SRC})