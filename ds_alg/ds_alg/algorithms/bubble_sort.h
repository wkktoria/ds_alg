#pragma once

#include <cstddef>
#include <utility>
#include <vector>

namespace ds_alg {
namespace algorithms {
template <typename T>
inline void BubbleSort(std::vector<T> &elements) {
  for (std::size_t i{0}; i < elements.size(); ++i) {
    for (std::size_t j{0}; j < elements.size() - i - 1; ++j) {
      if (elements.at(j) > elements.at(j + 1)) {
        std::swap(elements.at(j), elements.at(j + 1));
      }
    }
  }
}
}  // namespace algorithms
}  // namespace ds_alg
