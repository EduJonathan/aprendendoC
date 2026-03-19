cmake_minimum_required(VERSION 3.10)
project(permissoes_arquivos)

# C standard
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Output directories
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Include directories
include_directories(${CMAKE_SOURCE_DIR}/include)

# Library sources
set(LIB_SOURCES src/permissoes_lib.c)

# Create shared library
add_library(permissoes SHARED ${LIB_SOURCES})
target_include_directories(permissoes PUBLIC include)

# Set compiler flag for Windows DLL export (if needed)
if(WIN32 OR CYGWIN)
    target_compile_definitions(permissoes PRIVATE BUILDING_PERMISSOES_LIB)
endif()

# Executable sources
set(EXEC_SOURCES src/main.c)

# Create executable
add_executable(main ${EXEC_SOURCES})
target_link_libraries(main permissoes)
target_include_directories(main PRIVATE include)

# Set RPATH for executable to find the shared library in lib/ directory
set_target_properties(main PROPERTIES
    BUILD_RPATH "${CMAKE_BINARY_DIR}/lib"
    INSTALL_RPATH "$ORIGIN/lib"
)
