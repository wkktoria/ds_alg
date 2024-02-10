cmake_minimum_required(VERSION 3.14..3.26)
project(ds_alg VERSION 0.1
               DESCRIPTION "Data structures and algorithms implementations"
               LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(${PROJECT_NAME} INTERFACE)
target_compile_options(${PROJECT_NAME} INTERFACE -Wall -Wpedantic -Wextra)
target_compile_features(${PROJECT_NAME} INTERFACE cxx_std_17)

add_subdirectory(${PROJECT_NAME})

include(CTest)