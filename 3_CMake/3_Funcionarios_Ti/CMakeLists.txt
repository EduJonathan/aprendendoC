cmake_minimum_required(VERSION 3.20)
project(FuncionarioTI 
    VERSION 1.0.0 
    DESCRIPTION "Sistema de gerenciamento de funcionários TI"
    LANGUAGES C
)

# Build type padrão
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    set(CMAKE_BUILD_TYPE "Release" CACHE STRING "Build type" FORCE)
    message(STATUS "Build type não especificado → usando Release")
endif()

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

# Fontes
set(SOURCES
    src/main.c
    src/pessoa.c
    src/processador.c
    src/utils.c
)

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/include)

# Warnings
target_compile_options(${PROJECT_NAME} PRIVATE
    -Wall -Wextra -Wpedantic
    -Wshadow -Wconversion -Wsign-conversion
)

target_compile_options(${PROJECT_NAME} PRIVATE
    $<$<CONFIG:Debug>:-Werror -g -O0>
    $<$<CONFIG:Release>:-O2 -DNDEBUG>
)

# Sanitizers (opcional)
option(ENABLE_SANITIZERS "Habilitar sanitizers (Address + UB)" ON)
if(ENABLE_SANITIZERS AND CMAKE_BUILD_TYPE STREQUAL "Debug")
    if(CMAKE_C_COMPILER_ID MATCHES "GNU|Clang")
        target_compile_options(${PROJECT_NAME} PRIVATE 
            -fsanitize=address -fsanitize=undefined -fno-omit-frame-pointer
        )
        target_link_options(${PROJECT_NAME} PRIVATE 
            -fsanitize=address -fsanitize=undefined
        )
    endif()
endif()

install(TARGETS ${PROJECT_NAME} DESTINATION bin)
