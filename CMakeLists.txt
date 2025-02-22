cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
project(
    Grep
    VERSION 1.0
    LANGUAGES CXX
)

include_directories(include)

add_executable(
    grep
    main.cpp
    include/args.cpp
    include/args.h
    include/grep.cpp
    include/grep.h
)
