enable_testing()

find_package(googletest QUIET)
if(NOT googletest_FOUND)
    include(FetchContent)
    FetchContent_Declare(
      googletest
      GIT_REPOSITORY https://github.com/google/googletest.git
      GIT_TAG v1.14.0
    )
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    FetchContent_MakeAvailable(googletest)
endif()

add_executable(algorithms_test algorithms_test.cc)
target_link_libraries(algorithms_test PRIVATE GTest::gtest_main algorithms ${PROJECT_NAME})

add_executable(data_structures_test data_structures_test.cc)
target_link_libraries(data_structures_test PRIVATE GTest::gtest_main data_structures ${PROJECT_NAME})

include(GoogleTest)
gtest_discover_tests(algorithms_test)
gtest_discover_tests(data_structures_test)
