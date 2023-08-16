cmake_minimum_required(VERSION 3.26)
project(webDev C)

set(CMAKE_C_STANDARD 23)

add_library(webDev SHARED
        library.c
)


add_library(lib SHARED
        source/Server.c
        header/Server.h
        source/test.c)

add_executable(test source/test.c)

target_link_libraries(test lib)