project(tree)


set(SOURCE_PATH ${PROJECT_SOURCE_DIR}/*)
file(GLOB CPP_FILES_IN_UTILS "${SOURCE_PATH}*.c**")


add_executable(
    ${PROJECT_NAME}
    ${CPP_FILES_IN_UTILS}
)