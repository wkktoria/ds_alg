#include <cstddef>
#include <gtest/gtest.h>
#include <utility>
#include <vector>

namespace alg {
template <typename T> void InsertionSort(std::vector<T> &elements) {
  std::size_t i{1};

  while (i < elements.size()) {
    std::size_t j{i};

    while (j > 0 && elements.at(j - 1) > elements.at(j)) {
      std::swap(elements.at(j), elements.at(j - 1));
      --j;
    }

    ++i;
  }
}
} // namespace alg

namespace {
using alg::InsertionSort;

TEST(InsertionSortTest, SortElementsInAscendingOrder) {
  std::vector<int> elements{16, 4, 32, 2, 1, 128, 8, 64};
  InsertionSort(elements);

  std::vector<int> expected{1, 2, 4, 8, 16, 32, 64, 128};
  EXPECT_EQ(elements, expected);
}
} // namespace