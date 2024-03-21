#pragma once

#include <cstddef>
#include <utility>
#include <vector>

namespace ds_alg {
namespace algorithms {
template <typename T>
inline void InsertionSort(std::vector<T> &elements) {
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
}  // namespace algorithms
}  // namespace ds_alg
