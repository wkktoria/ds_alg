add_executable(selection_sort selection_sort.cc)
target_link_libraries(selection_sort PRIVATE GTest::gtest_main ds_alg)

add_executable(binary_search binary_search.cc)
target_link_libraries(binary_search PRIVATE GTest::gtest_main ds_alg)

include(GoogleTest)
gtest_discover_tests(selection_sort)
gtest_discover_tests(binary_search)