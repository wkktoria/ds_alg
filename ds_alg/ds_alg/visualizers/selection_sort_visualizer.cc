#include <ds_alg/visualizers/selection_sort_visualizer.h>

#include <algorithm>
#include <cstddef>
#include <raylib-cpp.hpp>
#include <thread>
#include <vector>

#include "utilities.h"

namespace ds_alg {
namespace visualizers {
void SelectionSortVisualization(std::vector<int> &bars) {
  for (std::size_t i{0}; i < bars.size() - 1; ++i) {
    std::size_t min_index{i};

    for (std::size_t j{i + 1}; j < bars.size(); ++j) {
      if (bars.at(j) < bars.at(min_index)) {
        min_index = j;
      }
    }

    if (i != min_index) {
      std::swap(bars.at(i), bars.at(min_index));

      BeginDrawing();
      ClearBackground(BLACK);
      DrawBars(bars, min_index);
      EndDrawing();

      std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
  }
}
}  // namespace visualizers
}  // namespace ds_alg
