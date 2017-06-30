cmake_minimum_required(VERSION 2.8)

project(citadel-sample)

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

set(CMAKE_CXX_STANDARD 14)

include_directories(../../citadel)
link_directories(${PROJECT_SOURCE_DIR}/../../citadel/libs)

add_executable(
	citadel-sample 
	../../citadel-sample-game.cpp
)

find_library( X11 x11 )
find_library( GL gl )
find_library( GLU glu )

target_link_libraries(
	citadel-sample

	citadel
	x11
	gl
	glu
)
