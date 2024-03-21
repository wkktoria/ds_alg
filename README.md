# ds_alg

My implementations of data structures and algorithms in C++.

## Build and run

:warning: Installation of some X11 libraries may be required to build it.

Build:

```console
cmake -S ds_alg -B build && cmake --build build 
```

Run tests:

```console
ctest --test-dir build/test --output-on-failure
```

Run visualizations:

UNIX:

```console
./build/executables/[algorithm]_visualization
```

Windows:

```console
.\build\executables\Debug\[algorithm]_visualization.exe
```

## Implemented visualizations

### Bubble sort

- [algorithm](ds_alg/ds_alg/algorithms/bubble_sort.h)
- [visualizer](ds_alg/ds_alg/visualizers/bubble_sort_visualizer.cc)

![Bubble sort visualization](gifs/bubble_sort.gif)

## Insertion sort

- [algorithm](ds_alg/ds_alg/algorithms/insertion_sort.h)
- [visualizer](ds_alg/ds_alg/visualizers/insertion_sort_visualizer.cc)

![Insertion sort visualization](gifs/insertion_sort.gif)

## Selection sort

- [algorithm](ds_alg/ds_alg/algorithms/selection_sort.h)
- [visualizer](ds_alg/ds_alg/visualizers/selection_sort_visualizer.cc)

![Selection visualization](gifs/selection_sort.gif)
