cmake_minimum_required(VERSION 3.14)

project(qttestsample VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/../lib")

find_package(Qt5 COMPONENTS Widgets REQUIRED)

FILE(GLOB SRC_FILES *.cpp)

add_executable(qtsrc
    ${SRC_FILES}
)

add_custom_command(TARGET qtsrc 
WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/..
    PRE_BUILD COMMAND node utils/checkfrozen.js frozen.json)



target_link_libraries(qtsrc Qt5::Widgets)
