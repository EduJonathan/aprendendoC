cmake_minimum_required(VERSION 3.10)
project(pong_gl C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

add_executable(pong src/main.c)

target_link_libraries(pong PRIVATE OpenGL::GL GLUT::GLUT m)
