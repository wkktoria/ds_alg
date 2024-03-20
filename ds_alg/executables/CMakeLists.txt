include(FetchContent)
FetchContent_Declare(
  raylib
  GIT_REPOSITORY https://github.com/raysan5/raylib.git
  GIT_TAG 5.0
  GIT_SHALLOW 1
)
FetchContent_MakeAvailable(raylib)

include(FetchContent)
FetchContent_Declare(
  raylib_cpp
  GIT_REPOSITORY https://github.com/RobLoach/raylib-cpp.git
  GIT_TAG v5.0.1
)
FetchContent_MakeAvailable(raylib_cpp)

add_executable(bubble_sort_visualizer bubble_sort_visualizer.cc)
target_link_libraries(bubble_sort_visualizer PRIVATE raylib raylib_cpp)

add_executable(insertion_sort_visualizer insertion_sort_visualizer.cc)
target_link_libraries(insertion_sort_visualizer PRIVATE raylib raylib_cpp)

add_executable(selection_sort_visualizer selection_sort_visualizer.cc)
target_link_libraries(selection_sort_visualizer PRIVATE raylib raylib_cpp)
