cmake_minimum_required(VERSION 3.17)
project(simple_perceptron)

set(CMAKE_CXX_STANDARD 20)

file(GLOB_RECURSE SOURCES RELATIVE ${CMAKE_SOURCE_DIR} "src/*.cpp")

add_executable(simple_perceptron ${SOURCES})