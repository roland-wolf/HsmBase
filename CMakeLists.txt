project(HsmBase)
cmake_minimum_required(VERSION 2.8)
set(CMAKE_BUILD_TYPE Debug)

add_custom_target(ide SOURCES src/hsmbase.h)

include_directories(${CMAKE_SOURCE_DIR}/src )

subdirs(test)
subdirs(example)

  
