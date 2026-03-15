cmake_minimum_required(VERSION 3.12)
project("lmgrd-runner" LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(lmgrd-runner WIN32 src/main.cpp)

set_target_properties(lmgrd-runner PROPERTIES PREFIX "")
