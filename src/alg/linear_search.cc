#include <cstddef>
#include <gtest/gtest.h>
#include <vector>

namespace alg {
template <typename T>
std::optional<std::size_t> LinearSearch(const std::vector<T> &elements,
                                        const T target) {
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
  const std::vector elements{1, 2, 4, 8, 16, 32, 64, 128};
  const auto result{LinearSearch(elements, 16)};

  EXPECT_EQ(4, result.value());
}

TEST(LinearSearchTest, ReturnProperValueWhenTargetValueIsNotFound) {
  const std::vector elements{1, 2, 4, 8, 16, 32, 64, 128};
  const auto result{LinearSearch(elements, 222)};

  EXPECT_EQ(std::nullopt, result);
}
} // namespace