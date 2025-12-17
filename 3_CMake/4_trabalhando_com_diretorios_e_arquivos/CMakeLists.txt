cmake_minimum_required(VERSION 3.10)

project(gerenciador_arquivos C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_executable(gerenciador_arquivos
    src/main.c
    src/utils.c
    src/dir_list.c
    src/file_ops.c
)

target_include_directories(gerenciador_arquivos
    PRIVATE includes
)

target_compile_options(gerenciador_arquivos
    PRIVATE -Wall -Wextra -Wpedantic
)
