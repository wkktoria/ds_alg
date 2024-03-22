#include <ds_alg/visualizers/insertion_sort_visualizer.h>

#include <algorithm>
#include <cstddef>
#include <raylib-cpp.hpp>
#include <thread>
#include <vector>

#include "utilities.h"

namespace ds_alg {
namespace visualizers {
void InsertionSortVisualization(std::vector<int> &bars) {
  std::size_t i{1};

  while (i < bars.size()) {
    std::size_t j{i};

    while (j > 0 && bars.at(j - 1) > bars.at(j)) {
      std::swap(bars.at(j), bars.at(j - 1));

      BeginDrawing();
      ClearBackground(BLACK);
      DrawBars(bars, j - 1);
      EndDrawing();

      std::this_thread::sleep_for(std::chrono::milliseconds(100));

      --j;
    }

    ++i;
  }
}
}  // namespace visualizers
}  // namespace ds_alg
