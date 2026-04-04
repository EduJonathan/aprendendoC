cmake_minimum_required(VERSION 3.10)
project(Calculadora C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK4 REQUIRED gtk4)

include_directories(${GTK4_INCLUDE_DIRS} include)
link_directories(${GTK4_LIBRARY_DIRS})

add_executable(calculadora src/main.c)
target_link_libraries(calculadora PRIVATE ${GTK4_LIBRARIES})
target_compile_options(calculadora PRIVATE ${GTK4_CFLAGS_OTHER})