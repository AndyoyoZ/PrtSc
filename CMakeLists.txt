cmake_minimum_required(VERSION 2.8)
project(PtrSc)

find_package(OpenCV REQUIRED)

if(NOT WIN32)
ADD_DEFINITIONS("-std=c++0x -O3")
endif(NOT WIN32)

include_directories(src) 
FILE(GLOB_RECURSE sourcefiles "src/*.cpp")
add_executable( PtrSc ${sourcefiles} )
target_link_libraries( PtrSc ${OpenCV_LIBS})




