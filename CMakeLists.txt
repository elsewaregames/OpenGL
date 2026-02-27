cmake_minimum_required(VERSION 3.16)
project(elsewareOpenGLWorkbench)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(external/glfw)

add_library(glad external/glad/src/glad.c)
target_include_directories(glad PUBLIC external/glad/include)

include_directories(external/glm)

file(GLOB_RECURSE SRC_FILES src/*.cpp)

add_executable(elsewareOpenGLWorkbench ${SRC_FILES})

target_link_libraries(elsewareOpenGLWorkbench glfw glad)