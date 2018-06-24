cmake_minimum_required(VERSION 3.10)

set(EXE_NAME notes)

project(${EXE_NAME})
subdirs(src)

set(CMAKE_CXX_STANDARD 11)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)