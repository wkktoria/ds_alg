#pragma once

#include <cstddef>
#include <gtest/gtest.h>
#include <vector>

namespace alg {
template <typename T>
[[nodiscard]] inline std::optional<std::size_t>
BinarySearch(const std::vector<T> &elements, const T target) {
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

  return {};
}
} // namespace alg
