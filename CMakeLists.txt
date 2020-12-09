cmake_minimum_required(VERSION 3.0)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug CACHE STRING "Debug" FORCE)
endif()

set (CMAKE_CXX_STANDARD 17)

project(sfml-cellular-automata)

set(EXECUTABLE_NAME "sfml-cellular-automata")
add_executable(
  ${EXECUTABLE_NAME}
  src/main.cpp
  src/CellularAutomaton.hpp
  src/CellularAutomaton.cpp
  src/GameOfLife.hpp
  src/GameOfLife.cpp
  src/Application.hpp
  src/Application.cpp
  src/State.hpp
  src/State.cpp
  src/ApplicationState.hpp
  src/ApplicationState.cpp
  src/MainMenuState.hpp
  src/MainMenuState.cpp
  src/Button.hpp
  src/Button.cpp
  )

target_link_libraries(${EXECUTABLE_NAME} sfml-graphics sfml-window sfml-system)
