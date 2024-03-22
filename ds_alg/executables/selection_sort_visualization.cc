#include <ds_alg/visualizers/selection_sort_visualizer.h>
#include <ds_alg/visualizers/utilities.h>

int main() {
  ds_alg::visualizers::RunVisualizer(
      "Selection Sort Visualization",
      ds_alg::visualizers::SelectionSortVisualization);

  return 0;
}
