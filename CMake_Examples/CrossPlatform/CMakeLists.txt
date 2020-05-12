cmake_minimum_required(VERSION 3.10)

set(TARGET_ARCH ${CMAKE_HOST_SYSTEM_PROCESSOR})


if(${TARGET_ARCH} STREQUAL "x86_64")   
  set(USR_LIBDIR /usr/lib/${TARGET_ARCH}-linux-gnu)
  set(SYSTEM_LIBDIR /system/lib/${TARGET_ARCH}-linux-gnu) 
  # ...

elseif({TARGET_ARCH} MATCHES "i*86")
  set(USR_LIBDIR /usr/lib/${TARGET_ARCH}-linux-gnu)
  set(SYSTEM_LIBDIR /system/lib/${TARGET_ARCH}-linux-gnu) 
  # ...

elseif(${TARGET_ARCH} STREQUAL "aarch64")
  set(USR_LIBDIR /usr/lib/aarch64-linux-gnu)
  set(SYSTEM_LIBDIR /system/lib/aarch64-linux-gnu)
  # ...

elseif(${TARGET_ARCH} STREQUAL "armhf")
  set(USR_LIBDIR /usr/lib/arm-linux-gnueabihf)
  set(SYSTEM_LIBDIR /system/lib/arm-linux-gnueabihf)	
  # ...

else()
	message(FATAL_ERROR "ERROR : Unsupported architecture.")
endif()

message("Host Architecture: ${TARGET_ARCH}")
message("USR_LIBDIR: ${USR_LIBDIR}")
message("SYSTEM_LIBDIR: ${SYSTEM_LIBDIR}")


if(${CMAKE_HOST_SYSTEM_PROCESSOR} STREQUAL "armhf") #for 32bit ARM
    set(ARM_NEON_FLAGS "-mfpu=neon")                     
elseif(${CMAKE_HOST_SYSTEM_PROCESSOR} STREQUAL "aarch64") #for 64bit ARM
    set(ARM_NEON_FLAGS "-O2 -ftree-vectorize")           
endif()

set(TARGET "example")
add_executable(${TARGET} main.cc)
