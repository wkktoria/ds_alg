#pragma once

#include <cstddef>
#include <optional>
#include <vector>

namespace ds_alg {
namespace algorithms {
template <typename T>
[[nodiscard]] inline std::optional<std::size_t> LinearSearch(
    const std::vector<T> &elements, const T target) {
  for (std::size_t i{0}; i < elements.size(); ++i) {
    if (elements.at(i) == target) {
      return i;
    }
  }

  return {};
}
}  // namespace algorithms
}  // namespace ds_alg
