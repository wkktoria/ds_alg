enable_testing()

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG v1.14.0
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(algorithms_test algorithms_test.cc)
target_include_directories(algorithms_test PRIVATE ../include/alg)
target_link_libraries(algorithms_test PRIVATE GTest::gtest_main ds_alg)

include(GoogleTest)
gtest_discover_tests(algorithms_test)