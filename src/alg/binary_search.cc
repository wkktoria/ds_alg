#include <cstddef>
#include <gtest/gtest.h>
#include <vector>

namespace alg {
int BinarySearch(const std::vector<int> &elements, const int target) {
  std::size_t left{0};
  std::size_t right{elements.size() - 1};

  while (left <= right) {
    std::size_t mid{(left + right) / 2};

    if (elements.at(mid) < target) {
      left = mid + 1;
    } else if (elements.at(mid) > target) {
      right = mid - 1;
    } else {
      return mid;
    }
  }

  return -1;
}
} // namespace alg

namespace {
using alg::BinarySearch;

TEST(BinarySearchTest, FindIndexOfTargetValue) {
  std::vector<int> elements{1, 2, 4, 8, 16, 32, 64, 128};
  int result{BinarySearch(elements, 16)};

  EXPECT_EQ(4, result);
}

TEST(BinarySearchTest, ReturnProperValueWhenTargetValueIsNotFound) {
  std::vector<int> elements{1, 2, 4, 8, 16, 32, 64, 128};
  int result{BinarySearch(elements, 222)};

  EXPECT_EQ(-1, result);
}
} // namespace