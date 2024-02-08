add_executable(selection_sort selection_sort.cc)
target_link_libraries(selection_sort PRIVATE GTest::gtest_main ds_alg)

add_executable(binary_search binary_search.cc)
target_link_libraries(binary_search PRIVATE GTest::gtest_main ds_alg)

add_executable(linear_search linear_search.cc)
target_link_libraries(linear_search PRIVATE GTest::gtest_main ds_alg)

add_executable(insertion_sort insertion_sort.cc)
target_link_libraries(insertion_sort PRIVATE GTest::gtest_main ds_alg)

include(GoogleTest)
gtest_discover_tests(selection_sort)
gtest_discover_tests(binary_search)
gtest_discover_tests(linear_search)
gtest_discover_tests(insertion_sort)