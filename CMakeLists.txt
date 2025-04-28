cmake_minimum_required(VERSION 3.30)
project(KursovaCPP)

set(CMAKE_CXX_STANDARD 17)

file(GLOB SOURCES "src/*.hpp"
                  "src/*.cpp")

add_executable(KursovaCPP ${SOURCES})
