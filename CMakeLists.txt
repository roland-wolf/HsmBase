project(HsmBase)
cmake_minimum_required(VERSION 3.12)

option(WITH_TEST "build with unit test" OFF)

add_custom_target(hsmbase_header SOURCES ${CMAKE_SOURCE_DIR}/src/hsmbase.h)  # show file in IDE

include_directories(${CMAKE_SOURCE_DIR}/src )

if(WITH_TEST)
    find_package(Boost COMPONENTS unit_test_framework REQUIRED)
    subdirs(test)
endif()

subdirs(example)
