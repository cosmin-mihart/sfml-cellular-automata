cmake_minimum_required(VERSION 3.0)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug CACHE STRING "Debug" FORCE)
endif()

set (CMAKE_CXX_STANDARD 17)

project(cellular-automata)

set(EXECUTABLE_NAME "cellular-automata")
add_executable(
  ${EXECUTABLE_NAME}
  src/main.cpp
  src/Map.hpp
  src/Map.cpp
  src/GameOfLife.hpp
  src/GameOfLife.cpp
  )


target_link_libraries(${EXECUTABLE_NAME} sfml-graphics sfml-window sfml-system)
