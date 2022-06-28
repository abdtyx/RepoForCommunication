# 依赖
cmake_minimum_required(VERSION 3.17)
# 项目名称
project(hello)
# 设置输出可执行文件路径
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

message( STATUS "This is a binary directory: " ${EXECUTABLE_OUTPUT_PATH})
aux_source_directory(. DIR_SRCS)
add_executable(${PROJECT_NAME} ${DIR_SRCS})