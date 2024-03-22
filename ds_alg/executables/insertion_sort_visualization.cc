#include <ds_alg/visualizers/insertion_sort_visualizer.h>
#include <ds_alg/visualizers/utilities.h>

int main() {
  ds_alg::visualizers::RunVisualizer(
      "Insertion Sort Visualization",
      ds_alg::visualizers::InsertionSortVisualization);

  return 0;
}
