#include <algorithm>
#include <chrono>
#include <raylib-cpp.hpp>
#include <thread>
#include <utility>
#include <vector>

#include "constants.h"
#include "utilities.h"

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

int main() {
  raylib::Window window(kScreenWidth, kScreenHeight,
                        "Selection Sort Visualization");
  window.SetTargetFPS(60);

  auto bars{CreateBars()};

  while (!window.ShouldClose()) {
    BeginDrawing();
    ClearBackground(BLACK);

    SelectionSortVisualization(bars);
    DrawBars(bars);

    EndDrawing();
  }

  return 0;
}
