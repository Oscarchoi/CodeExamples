CMAKE_MINIMUM_REQUIRED (VERSION 3.10)
SET(CMAKE_CXX_COMPILER "g++")
SET(CMAKE_CXX_FLAGS "-std=c++14")

# 프로젝트 지정
project(ExecuteProcess)

### Generation Phase 프로세스 실행 ###
## Prior to Build System Generation
execute_process(COMMAND uname -m OUTPUT_VARIABLE ARCH
                                 RESULT_VARIABLE RETURN)
message("Process result: " ${RETURN})
message("Process stdout: " ${ARCH})


### Build Phase 프로세스 실행 ###
add_custom_target(boo ALL
  COMMAND echo "This is ALL target 'boo'"
  VERBATIM
)

# 빌드 타겟 소스 지정 및 추가
set(TARGET "foo")
set(SRC foo.cc)
add_executable(${TARGET} ${SRC})

### 타겟에 종속적인 커맨드 실행 ###
add_custom_command(
  TARGET ${TARGET}
  PRE_LINK
  COMMAND "pwd"
  COMMENT "This command(pwd) is executed after compilation but before linking ${TARGET}" 
)
