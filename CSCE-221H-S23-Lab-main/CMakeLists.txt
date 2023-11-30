# SPDX-License-Identifier: MIT

cmake_minimum_required(VERSION 3.14)
project(
  CSCE221HLab
  VERSION 0.5
  LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_EXTENSIONS OFF)

add_subdirectory(src)

include(CTest)
enable_testing()
add_subdirectory(test)