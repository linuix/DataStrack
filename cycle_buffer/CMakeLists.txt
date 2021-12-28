

project(cycle_buffer)

include_directories(../comm/include)


add_executable(
    ${PROJECT_NAME}
    src/cycle_buffer.c
    src/main.c
)

