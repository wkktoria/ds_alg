#include <ds_alg/visualizers/bubble_sort_visualizer.h>
#include <ds_alg/visualizers/utilities.h>

int main() {
  ds_alg::visualizers::RunVisualizer(
      "Bubble Sort Visualization",
      ds_alg::visualizers::BubbleSortVisualization);

  return 0;
}
