cmake_minimum_required(VERSION 3.20)
project(Lab3Scheme10 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(MSVC)
    add_compile_options(/W4 /permissive- /utf-8 /Zc:__cplusplus)
    add_compile_definitions(NOMINMAX WIN32_LEAN_AND_MEAN)
else()
    add_compile_options(-Wall -Wextra -pedantic)
endif()

add_executable(prog
    src/main.cpp
    src/computation.cpp
    src/action.cpp
)
target_include_directories(prog PRIVATE src)
