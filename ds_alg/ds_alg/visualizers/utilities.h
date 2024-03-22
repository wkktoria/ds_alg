#pragma once

#include <functional>
#include <optional>
#include <string>
#include <vector>

namespace ds_alg {
namespace visualizers {
void DrawBars(const std::vector<int> &bars,
              std::optional<int> selected_bar = std::nullopt);

[[nodiscard]] std::vector<int> CreateBars();

void RunVisualizer(const std::string &window_title,
                   std::function<void(std::vector<int> &)> visualization);
}  // namespace visualizers
}  // namespace ds_alg
