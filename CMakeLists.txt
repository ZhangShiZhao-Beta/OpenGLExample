cmake_minimum_required(VERSION 3.10)
project(OpenGLExample)

set(CMAKE_CXX_STANDARD 14)

# 添加子目录
add_subdirectory(EntryLevel)

# 创建主程序，并链接子目录生成的库
add_executable(OpenGLExample main.cpp)
target_link_libraries(OpenGLExample PRIVATE EntryLevel)
