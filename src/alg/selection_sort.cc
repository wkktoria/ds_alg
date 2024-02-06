#include <cstddef>
#include <gtest/gtest.h>
#include <utility>
#include <vector>

namespace alg {
void SelectionSort(std::vector<int> &elements) {
  for (std::size_t i{0}; i < elements.size() - 1; ++i) {
    std::size_t min_index{i};

    for (std::size_t j{i + 1}; j < elements.size(); ++j) {
      if (elements.at(j) < elements.at(min_index)) {
        min_index = j;
      }
    }

    if (i != min_index) {
      std::swap(elements.at(i), elements.at(min_index));
    }
  }
}
} // namespace alg

namespace {
using alg::SelectionSort;

TEST(SelectionSortTest, SortElementsInAscendingOrder) {
  std::vector<int> elements{16, 4, 32, 2, 1, 128, 8, 64};
  SelectionSort(elements);

  std::vector<int> expected{1, 2, 4, 8, 16, 32, 64, 128};
  EXPECT_EQ(elements, expected);
}
} // namespace