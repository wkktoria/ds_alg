#include <ds_alg/visualizers/utilities.h>

#include <algorithm>
#include <optional>
#include <random>
#include <raylib-cpp.hpp>
#include <vector>

#include "constants.h"

namespace ds_alg {
namespace visualizers {
void DrawBars(const std::vector<int> &bars, std::optional<int> selected_bar) {
  int width{kScreenWidth / kNumberOfBars};

  for (auto i{0}; i < kNumberOfBars; ++i) {
    if (selected_bar.has_value() && selected_bar.value() == i) {
      DrawRectangle(i * width, kScreenWidth - bars.at(i), width, bars.at(i),
                    BLUE);
    } else {
      DrawRectangle(i * width, kScreenWidth - bars.at(i), width, bars.at(i),
                    WHITE);
    }
  }
}

[[nodiscard]] std::vector<int> CreateBars() {
  std::random_device random_device{};
  std::mt19937 rng(random_device());
  std::uniform_int_distribution<std::mt19937::result_type> distribution(
      1, kScreenHeight / kNumberOfBars);

  std::vector<int> bars(kNumberOfBars);
  for (auto i{0}; i < kNumberOfBars; ++i) {
    bars.at(i) = (i + distribution(rng)) * distribution(rng);
  }
  std::shuffle(std::begin(bars), std::end(bars), rng);

  return bars;
}

void RunVisualizer(const std::string &window_title,
                   std::function<void(std::vector<int> &)> visualization) {
  raylib::Window window(kScreenWidth, kScreenHeight, window_title);
  window.SetTargetFPS(60);

  auto bars{CreateBars()};

  while (!window.ShouldClose()) {
    BeginDrawing();
    ClearBackground(BLACK);

    visualization(bars);
    DrawBars(bars);

    EndDrawing();
  }
}
}  // namespace visualizers
}  // namespace ds_alg
