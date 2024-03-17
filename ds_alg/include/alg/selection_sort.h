#pragma once

#include <cstddef>
#include <utility>
#include <vector>

namespace alg {
template <typename T>
inline void SelectionSort(std::vector<T> &elements) {
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
}  // namespace alg
