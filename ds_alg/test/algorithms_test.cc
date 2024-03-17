#include <gtest/gtest.h>

#include <cstddef>
#include <optional>
#include <vector>

#include "binary_search.h"
#include "bubble_sort.h"
#include "insertion_sort.h"
#include "linear_search.h"
#include "selection_sort.h"

namespace {
using alg::BinarySearch;
using alg::BubbleSort;
using alg::InsertionSort;
using alg::LinearSearch;
using alg::SelectionSort;

const std::vector kIntegerElements{16, 4, 32, 2, 1, 128, 8, 64};
const std::vector kSortedIntegerElements{1, 2, 4, 8, 16, 32, 64, 128};
}  // namespace

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