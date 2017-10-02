cmake_minimum_required(VERSION 3.8)
project(BlackCurtain)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        src/main.cpp
        src/CImg.h
        CMakeSetup.rc)

# Add libraries statically for standalone executable
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libgcc -static-libstdc++")

# Add flags to hide console
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  -Wl,-subsystem,windows")

add_executable(BlackCurtain ${SOURCE_FILES})

if( CMAKE_BUILD_TYPE EQUAL "Release")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")
endif()
