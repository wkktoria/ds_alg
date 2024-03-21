#include <ds_alg/visualizers/bubble_sort_visualizer.h>

#include <algorithm>
#include <raylib-cpp.hpp>
#include <thread>
#include <vector>

#include "constants.h"
#include "utilities.h"

namespace ds_alg {
namespace visualizers {
void BubbleSortVisualization(std::vector<int> &bars) {
  for (auto i{0}; i < kNumberOfBars; ++i) {
    for (auto j{0}; j < kNumberOfBars - i - 1; ++j) {
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

void RunBubbleSortVisualizer() {
  raylib::Window window(kScreenWidth, kScreenHeight,
                        "Bubble Sort Visualization");
  window.SetTargetFPS(60);

  auto bars{CreateBars()};

  while (!window.ShouldClose()) {
    BeginDrawing();
    ClearBackground(BLACK);

    BubbleSortVisualization(bars);
    DrawBars(bars);

    EndDrawing();
  }
}
}  // namespace visualizers
}  // namespace ds_alg
