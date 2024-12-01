cmake_minimum_required(VERSION 3.28)

project(game
    VERSION 0.1
    DESCRIPTION "A simple game built with SFML"
    LANGUAGES CXX)

# TODO: Determine if we really need to include headers
set(SOURCES src/main.cpp)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON) # We need this for clangd to get a compile_commands.json
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

include(FetchContent)

# SFML Library
FetchContent_Declare(sfml
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(sfml)

# FMT Library
FetchContent_Declare(
    fmt
    GIT_REPOSITORY https://github.com/fmtlib/fmt.git
    GIT_TAG master
    GIT_SHALLOW ON
)
FetchContent_MakeAvailable(fmt)

add_executable(game ${SOURCES})
target_link_libraries(game PRIVATE sfml-graphics fmt)
target_compile_options(game PRIVATE
    -Wall -Wextra -Wpedantic -Werror -Wno-error=unused-parameter -Wno-error=unused-variable
    -Wno-error=unused-but-set-variable)
