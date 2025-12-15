cmake_minimum_required(VERSION 3.12)
project(FuncionarioTI VERSION 1.0.0 LANGUAGES C)

# Configurar padrão C17 com todas as warnings
set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

if(CMAKE_COMPILER_IS_GNUCC OR CMAKE_C_COMPILER_ID MATCHES "Clang")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Wpedantic -Werror")
endif()

# Incluir diretórios
include_directories(include)

# Adicionar executável
add_executable(c_moderno_example
    src/main.c
    src/pessoa.c
    src/processador.c
    src/utils.c
)

# Configurações de instalação
install(TARGETS c_moderno_example DESTINATION bin)