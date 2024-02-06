#include <cstddef>
#include <gtest/gtest.h>
#include <vector>

namespace alg {
int LinearSearch(const std::vector<int> &elements, const int target) {
  for (std::size_t i{0}; i < elements.size(); ++i) {
    if (elements.at(i) == target) {
      return i;
    }
  }

  return -1;
}
} // namespace alg

namespace {
using alg::LinearSearch;

TEST(LinearSearchTest, FindIndexOfTargetValue) {
  std::vector<int> elements{1, 2, 4, 8, 16, 32, 64, 128};
  int result{LinearSearch(elements, 16)};

  EXPECT_EQ(4, result);
}

TEST(LinearSearchTest, ReturnProperValueWhenTargetValueIsNotFound) {
  std::vector<int> elements{1, 2, 4, 8, 16, 32, 64, 128};
  int result{LinearSearch(elements, 222)};

  EXPECT_EQ(-1, result);
}
} // namespace