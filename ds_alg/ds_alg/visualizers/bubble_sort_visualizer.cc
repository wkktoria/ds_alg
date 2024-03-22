#include <ds_alg/visualizers/bubble_sort_visualizer.h>

#include <algorithm>
#include <raylib-cpp.hpp>
#include <thread>
#include <vector>

#include "utilities.h"

namespace ds_alg {
namespace visualizers {
void BubbleSortVisualization(std::vector<int> &bars) {
  for (auto i{0U}; i < bars.size(); ++i) {
    for (auto j{0U}; j < bars.size() - i - 1; ++j) {
      if (bars.at(j) > bars.at(j + 1)) {
        std::swap(bars.at(j), bars.at(j + 1));

        BeginDrawing();
        ClearBackground(BLACK);
        DrawBars(bars, j + 1);
        EndDrawing();

        std::this_thread::sleep_for(std::chrono::milliseconds(100));
      }
    }
  }
}
}  // namespace visualizers
}  // namespace ds_alg
