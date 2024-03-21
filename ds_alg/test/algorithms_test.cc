#include <ds_alg/algorithms/binary_search.h>
#include <ds_alg/algorithms/bubble_sort.h>
#include <ds_alg/algorithms/insertion_sort.h>
#include <ds_alg/algorithms/linear_search.h>
#include <ds_alg/algorithms/selection_sort.h>
#include <gtest/gtest.h>

#include <cstddef>
#include <optional>

#include "constants.h"

namespace ds_alg_test {
namespace algorithms_test {
using ds_alg::algorithms::BinarySearch;
using ds_alg::algorithms::BubbleSort;
using ds_alg::algorithms::InsertionSort;
using ds_alg::algorithms::LinearSearch;
using ds_alg::algorithms::SelectionSort;
using ds_alg_test::constants::kIntegerElements;
using ds_alg_test::constants::kSortedIntegerElements;

TEST(BinarySearchTest, FindIndexOfIntegerTargetValue) {
  const int target_value{16};
  const std::size_t expected_index{4};
  const auto result{BinarySearch(kSortedIntegerElements, target_value).value()};

  EXPECT_EQ(result, expected_index);
}

TEST(BinarySearchTest, ReturnProperValueWhenTargetValueIsNotFound) {
  const int non_existing_target_value{2222};
  const std::nullopt_t expected_value{std::nullopt};
  const auto result{
      BinarySearch(kSortedIntegerElements, non_existing_target_value)};

  EXPECT_EQ(result, expected_value);
}

TEST(BubbleSortTest, SortIntegerElementsInAscendingOrder) {
  auto elements{kIntegerElements};
  BubbleSort(elements);

  EXPECT_EQ(elements, kSortedIntegerElements);
}

TEST(InsertionSortTest, SortIntegerElementsInAscendingOrder) {
  auto elements{kIntegerElements};
  InsertionSort(elements);

  EXPECT_EQ(elements, kSortedIntegerElements);
}

TEST(LinearSearchTest, FindIndexOfIntegerTargetValue) {
  const int target_value{8};
  const std::size_t expected_index{6};
  const auto result{LinearSearch(kIntegerElements, target_value).value()};

  EXPECT_EQ(result, expected_index);
}

TEST(LinearSearchTest, ReturnProperValueWhenTargetValueIsNotFound) {
  const int non_existing_target_value{2424};
  const auto expected_value{std::nullopt};
  const auto result{LinearSearch(kIntegerElements, non_existing_target_value)};

  EXPECT_EQ(result, expected_value);
}

TEST(SelectionSort, SortIntegerElementsInAscendingOrder) {
  auto elements{kIntegerElements};
  SelectionSort(elements);

  EXPECT_EQ(elements, kSortedIntegerElements);
}
}  // namespace algorithms_test
}  // namespace ds_alg_test
