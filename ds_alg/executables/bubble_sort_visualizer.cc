#include "raylib-cpp.hpp"
#include <algorithm>
#include <chrono>
#include <iterator>
#include <optional>
#include <random>
#include <thread>
#include <utility>
#include <vector>

namespace {
constexpr int kScreenWidth{300};
constexpr int kScreenHeight{300};
constexpr int kNumberOfBars{50};
} // namespace

void DrawBars(const std::vector<int> &bars,
              std::optional<int> selected_bar = std::nullopt) {
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

int main() {
  std::random_device random_device{};
  std::mt19937 rng(random_device());
  std::uniform_int_distribution<std::mt19937::result_type> distribution(
      1, kScreenHeight / kNumberOfBars);

  std::vector<int> bars(kNumberOfBars);
  for (auto i{0}; i < kNumberOfBars; ++i) {
    bars.at(i) = (i + distribution(rng)) * distribution(rng);
  }
  std::shuffle(std::begin(bars), std::end(bars), rng);

  raylib::Window window(kScreenWidth, kScreenHeight,
                        "Bubble Sort Visualization");
  window.SetTargetFPS(60);

  while (!window.ShouldClose()) {
    BeginDrawing();
    ClearBackground(BLACK);

    BubbleSortVisualization(bars);
    DrawBars(bars);

    EndDrawing();
  }

  return 0;
}