cmake_minimum_required(VERSION 3.10)

set(EXE_NAME notes)

project(${EXE_NAME})
subdirs(src
        test)

set(CMAKE_CXX_STANDARD 17)

set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
include_directories(${INCLUDE_DIR}
        ${INCLUDE_DIR}/console
        ${INCLUDE_DIR}/logging
        ${INCLUDE_DIR}/note
        ${INCLUDE_DIR}/note/repository
        ${INCLUDE_DIR}/util)

enable_testing()