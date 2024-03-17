#include <algorithm>
#include <chrono>
#include <raylib-cpp.hpp>
#include <thread>
#include <utility>
#include <vector>

#include "constants.h"
#include "utilities.h"

void InsertionSortVisualization(std::vector<int> &bars) {
  std::size_t i{1};

  while (i < kNumberOfBars) {
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

int main() {
  raylib::Window window(kScreenWidth, kScreenHeight,
                        "Insertion Sort Visualization");
  window.SetTargetFPS(60);

  auto bars{CreateBars()};

  while (!window.ShouldClose()) {
    BeginDrawing();
    ClearBackground(BLACK);

    InsertionSortVisualization(bars);
    DrawBars(bars);

    EndDrawing();
  }

  return 0;
}
