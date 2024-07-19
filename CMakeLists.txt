cmake_minimum_required(VERSION 3.10)

project(fe8086 C)

file(GLOB SRC_FILES ${PROJECT_SOURCE_DIR}/src/*.c)

include_directories(${PROJECT_SOURCE_DIR}/include)
add_executable(${PROJECT_NAME} ${SRC_FILES})