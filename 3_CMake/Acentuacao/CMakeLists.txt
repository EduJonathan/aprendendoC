cmake_minimum_required(VERSION 3.16)
project(MeuProjeto LANGUAGES C)

# Forçar UTF-8 no MSVC (Windows)
if (MSVC)
    add_compile_options("/utf-8")
endif()

# Forçar UTF-8 no GCC/Clang (Linux, macOS, MinGW)
if (CMAKE_C_COMPILER_ID MATCHES "GNU|Clang")
    add_compile_options(-Wall -Wextra -finput-charset=UTF-8 -fexec-charset=UTF-8)
endif()

add_executable(meu_programa main.c)
