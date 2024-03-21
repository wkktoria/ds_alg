find_package(raylib QUIET)
if(NOT raylib_FOUND)
    include(FetchContent)
    FetchContent_Declare(
      raylib
      GIT_REPOSITORY https://github.com/raysan5/raylib.git
      GIT_TAG 5.0
      GIT_SHALLOW 1
    )
    FetchContent_MakeAvailable(raylib)
endif()

find_package(raylib_cpp QUIET)
if(NOT raylib_cpp_FOUND)
    include(FetchContent)
    FetchContent_Declare(
      raylib_cpp
      GIT_REPOSITORY https://github.com/RobLoach/raylib-cpp.git
      GIT_TAG v5.0.1
    )
    FetchContent_MakeAvailable(raylib_cpp)
endif()

add_library(visualizers bubble_sort_visualizer.cc insertion_sort_visualizer.cc selection_sort_visualizer.cc)
target_link_libraries(visualizers PUBLIC ${PROJECT_NAME})
target_link_libraries(visualizers PRIVATE raylib raylib_cpp)
