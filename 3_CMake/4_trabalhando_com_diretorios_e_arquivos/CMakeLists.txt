cmake_minimum_required(VERSION 3.10)

project(gerenciador_arquivos
    VERSION 1.0
    LANGUAGES C
)

# Padrão da linguagem
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

# Arquivos fonte
set(SOURCES
    src/main.c
    src/utils.c
    src/dir_list.c
    src/file_ops.c
)

# Executável
add_executable(${PROJECT_NAME} ${SOURCES})

# Diretórios de includes
target_include_directories(${PROJECT_NAME}
    PRIVATE
        ${PROJECT_SOURCE_DIR}/includes
)

# Warnings por compilador
if (MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /W4)
else()
    target_compile_options(${PROJECT_NAME} PRIVATE
        -Wall
        -Wextra
        -Wpedantic
    )
endif()

# (Opcional) Instalação futura
# install(TARGETS ${PROJECT_NAME} DESTINATION bin)
