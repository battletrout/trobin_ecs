cmake_minimum_required(VERSION 3.25)
project(btCmakeProj VERSION 0.1.0 LANGUAGES C CXX)

# Recommended settings from https://www.youtube.com/watch?v=4U-lnfxY2U0
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
    fmt
    GIT_REPOSITORY https://github.com/fmtlib/fmt.git
    GIT_TAG 10.2.1
)

FetchContent_Declare(
    SDL2
    GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
    GIT_TAG release-2.30.3
)

FetchContent_MakeAvailable(fmt)
FetchContent_MakeAvailable(SDL2)

include_directories(src)
# Debug tools directory, remove for release
include_directories(tools)

add_executable(btCmakeProj main.cpp)
target_link_libraries(btCmakeProj PRIVATE fmt::fmt)
target_link_libraries(btCmakeProj PRIVATE SDL2::SDL2)

#// recommended from yt vid