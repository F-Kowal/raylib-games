cmake_minimum_required(VERSION 3.15)
project(raylib-games LANGUAGES C CXX)

set(CMAKE_POLICY_VERSION_MINIMUM 3.5)

include(FetchContent)
FetchContent_Declare(
    raylib
    GIT_REPOSITORY https://github.com/raysan5/raylib.git
    GIT_TAG master
)
FetchContent_MakeAvailable(raylib)


add_subdirectory(tetris)