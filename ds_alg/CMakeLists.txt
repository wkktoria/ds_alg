cmake_minimum_required(VERSION 3.14..3.26)
project(ds_alg VERSION 0.2
               DESCRIPTION "Data structures and algorithms implementations and visuailzations"
               LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(${PROJECT_NAME} INTERFACE)

if(UNIX)
    target_compile_options(${PROJECT_NAME} INTERFACE -Wall -Wpedantic -Wextra)
endif()

target_compile_features(${PROJECT_NAME} INTERFACE cxx_std_17)
target_include_directories(${PROJECT_NAME} INTERFACE ${PROJECT_SOURCE_DIR})

add_subdirectory(${PROJECT_NAME})
add_subdirectory(executables)
add_subdirectory(test)

include(CTest)
