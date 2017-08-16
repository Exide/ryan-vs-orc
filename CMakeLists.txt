cmake_minimum_required(VERSION 3.8)
project(Ryan_vs_Orc)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES main.cpp random.h character.h weapon.h ansi.h)
add_executable(Ryan_vs_Orc ${SOURCE_FILES})