cmake_minimum_required(VERSION 3.10)

# Nome do projeto
project(conversor_final LANGUAGES C)

# Padrão da linguagem C
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Diretórios de saída
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# =========================
# Biblioteca estática
# =========================

add_library(converter STATIC
    src/converter.c
)

target_include_directories(converter
    PUBLIC
        ${CMAKE_SOURCE_DIR}/include
)

# =========================
# Executável final
# =========================

add_executable(conversor_final
    src/main.c
)

target_link_libraries(conversor_final
    PRIVATE
        converter
)

target_include_directories(conversor_final
    PRIVATE
        ${CMAKE_SOURCE_DIR}/include
)
