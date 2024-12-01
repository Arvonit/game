cmake_minimum_required(VERSION 3.28)
project(CMakeSFMLProject LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON) # We need this for clangd to get a compile_commands.json
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

add_executable(game src/main.cpp)
target_link_libraries(game PRIVATE sfml-graphics)
target_compile_features(game PRIVATE cxx_std_23)
