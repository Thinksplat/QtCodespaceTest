cmake_minimum_required(VERSION 3.14)

enable_testing()

project(QtTDD)

add_subdirectory(qtsrc)
add_subdirectory(tests)

add_custom_target(CheckkFrozen ALL
WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    COMMAND node utils/checkfrozen.js frozen.json)

