cmake_minimum_required(VERSION 3.0)
project(cow)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SRC_FILES src/main.cpp)

# Include glad, GLFW, GLM
add_subdirectory(external/glfw/glfw-master)
add_subdirectory(external/assimp)
include_directories(include external/glfw/glfw-master/include external/assimp/include)

# Add source files
add_executable(cow  ${SRC_FILES}
    src/main.cpp
    src/glad.c
)

target_link_libraries(cow glfw assimp ${CMAKE_DL_LIBS})

# 设置编译选项
target_compile_options(cow PRIVATE -Wall -g)
