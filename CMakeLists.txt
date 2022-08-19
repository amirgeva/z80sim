cmake_minimum_required(VERSION 3.16)
project(z80sim)

option(BUILD_SHELL "Build command shell with simulated IO and GPU" ON)

add_library(cpu cpu/accessors.cpp cpu/consts.h cpu/utils.cpp cpu/z80.cpp cpu/accessors.h cpu/instructions.cpp cpu/types.h cpu/utils.h cpu/z80.h)

if (BUILD_SHELL)
	find_package(OpenCV CONFIG REQUIRED)
	add_library(zio zio/zio.h zio/zio.cpp zio/zgpu.h zio/zgpu.cpp zio/protocol.h zio/protocol.cpp)
	add_executable(zshell zshell/main.cpp)
	target_include_directories(zio PRIVATE cpu)

	target_include_directories(zshell PRIVATE 
		${CMAKE_CURRENT_SOURCE_DIR}/cpu
		${CMAKE_CURRENT_SOURCE_DIR}/zio
		${CMAKE_CURRENT_SOURCE_DIR}/cxx/include
	)

	target_link_libraries(zshell PRIVATE cpu zio opencv_core opencv_highgui)
endif (BUILD_SHELL)
