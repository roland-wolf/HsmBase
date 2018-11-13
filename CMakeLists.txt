project(HsmBase)
cmake_minimum_required(VERSION 2.8)
set(CMAKE_BUILD_TYPE Debug)

option(WITH_TEST "build with tests" OFF)

add_custom_target(hsmbase_header SOURCES ${CMAKE_SOURCE_DIR}/src/hsmbase.h)  # show file in IDE

include_directories(${CMAKE_SOURCE_DIR}/src )

if(WITH_TEST)
    subdirs(test)
endif()

subdirs(example)

  
