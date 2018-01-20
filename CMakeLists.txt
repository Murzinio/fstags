cmake_minimum_required(VERSION 3.10)
project(fstags)
add_executable(fstags ${CMAKE_CURRENT_SOURCE_DIR}/sources/main.cpp 
                ${CMAKE_CURRENT_SOURCE_DIR}/sources/program.cpp
                ${CMAKE_CURRENT_SOURCE_DIR}/sources/user_io.cpp
                ${CMAKE_CURRENT_SOURCE_DIR}/sources/data_manager.cpp)

add_executable(fstags_tests ${CMAKE_CURRENT_SOURCE_DIR}/tests/main.cpp
                ${CMAKE_CURRENT_SOURCE_DIR}/tests/program.cpp
                ${CMAKE_CURRENT_SOURCE_DIR}/tests/user_io.cpp
                ${CMAKE_CURRENT_SOURCE_DIR}/tests/data_manager.cpp)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/headers)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/tests)

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    target_link_libraries(fstags stdc++fs) #gcc filesystem
    set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror -pedantic")
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror -pedantic")
endif()

set(fstags_version 0.0)

# C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_BUILD_TYPE Debug)
