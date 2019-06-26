cmake_minimum_required(VERSION 3.13)
project(DataStrack)

set(CMAKE_CXX_STANDARD 11)


add_definitions(-Dlog=printf)

add_executable(DataStrack
        main.cpp
        list/link_list.cpp
        list/link_list.h
        sort/sort_list.cpp
        sort/sort_list.h
        seek/seek_list.cpp
        seek/seek_list.h
        list/array_list.cpp
        list/array_list.h
        list/list.cpp
        list/list.h)