# 출력
message("Practice Code for CMakeLists.txt")

# 공통 컴파일 옵션 - 이후 선언되는 타겟에 적용
set(BUILD_OPTIONS -Wall;-Weffc++) # 다중 옵션 추가시 리스트 
add_compile_options(${BUILD_OPTIONS}) 

# 빌드 타겟 지정
set(TARGET "foo")
set(SRC foo.cc)
add_executable(${TARGET} ${SRC})

# 타겟 빌드 옵션 추가
set_target_properties(${TARGET} PROPERTIES COMPILE_OPTIONS "-g")