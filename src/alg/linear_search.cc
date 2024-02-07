#include <cstddef>
#include <gtest/gtest.h>
#include <vector>

namespace alg {
std::optional<std::size_t> LinearSearch(const std::vector<int> &elements,
                                        const int target) {
  for (std::size_t i{0}; i < elements.size(); ++i) {
    if (elements.at(i) == target) {
      return i;
    }
  }

  return {};
}
} // namespace alg

namespace {
using alg::LinearSearch;

TEST(LinearSearchTest, FindIndexOfTargetValue) {
  std::vector elements{1, 2, 4, 8, 16, 32, 64, 128};
  auto result{LinearSearch(elements, 16)};

  EXPECT_EQ(4, result.value());
}

TEST(LinearSearchTest, ReturnProperValueWhenTargetValueIsNotFound) {
  std::vector elements{1, 2, 4, 8, 16, 32, 64, 128};
  auto result{LinearSearch(elements, 222)};

  EXPECT_EQ(std::nullopt, result);
}
} // namespace