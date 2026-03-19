cmake_minimum_required(VERSION 3.10)

project(println_asm LANGUAGES C ASM_NASM)

# =========================
# Padrão C
# =========================
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

# =========================
# Diretórios de saída
# =========================
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# =========================
# Biblioteca estática (NASM)
# =========================
add_library(println STATIC
    assembly/println.asm
)

# Força formato ELF64 (Linux x86_64)
set_source_files_properties(
    assembly/println.asm
    PROPERTIES
        LANGUAGE ASM_NASM
        COMPILE_FLAGS "-f elf64"
)

target_include_directories(println
    PUBLIC
        ${CMAKE_SOURCE_DIR}/include
)

# =========================
# Executável
# =========================
add_executable(programa
    src/main.c
)

target_link_libraries(programa
    PRIVATE
        println
)

target_include_directories(programa
    PRIVATE
        ${CMAKE_SOURCE_DIR}/include
)
