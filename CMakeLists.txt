cmake_minimum_required(VERSION 2.8.4)
project(F4PL)
set(F4PL_VERSION_MAJOR 0)
set(F4PL_VERSION_MINOR 1)
set(F4PL_VERSION_PATCH 0)
set(F4PL_VERSION_STRING "${F4PL_VERSION_MAJOR}.${F4PL_VERSION_MINOR}.${F4PL_VERSION_PATCH}")

find_package(Boost REQUIRED COMPONENTS program_options regex log thread system)
include_directories(${Boost_INCLUDE_DIRS})
include_directories(Compiler)
include_directories(${PROJECT_BINARY_DIR})

configure_file(
    ${PROJECT_SOURCE_DIR}/version.h.in
    ${PROJECT_BINARY_DIR}/version.h
    )

file(COPY test.f4 DESTINATION "${PROJECT_BINARY_DIR}")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Compiler/Compiler.cpp Compiler/Parser.cpp Compiler/Lexer.cpp Compiler/Errors.cpp)
add_executable(F4PL ${SOURCE_FILES})
target_link_libraries(F4PL ${Boost_LIBRARIES})