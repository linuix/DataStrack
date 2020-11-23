cmake_minimum_required(VERSION 3.13)
project(DataStrack)

set(CMAKE_CXX_STANDARD 11)


# add_definitions(-DLOGD=printf)


set(LIBRARY_OUTPUT_PATH ./out/${PROJECT_NAME}/lib)
set(EXECUTABLE_OUTPUT_PATH ./out/${PROJECT_NAME}/execute)

include_directories(./comm/include/)
include_directories(./sort)

add_compile_options(-ld)
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

        
project(test_list)
set(CMAKE_VERBOSE_MAKEFILE ON)

include_directories(./comm/include/)


add_compile_options(-lm)
add_executable(${PROJECT_NAME}
        std_data_strack/test_list.cpp
)       
