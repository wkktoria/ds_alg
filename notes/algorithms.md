# Algorithms

- [Search algorithms](#search-algorithms)
  - [Binary search](#binary-search)
  - [Linear search](#linear-search)
- [Sorting algorithms](#sorting-algorithms)
  - [Bubble sort](#bubble-sort)
  - [Insertion sort](#insertion-sort)
  - [Selection sort](#selection-sort)

## Search algorithms

### Binary search

>[!WARNING]
> To binary search to work, array must be sorted.

Binary search compares the target value to the middle element of the array, if they are not equal, the half in which the target cannot lie is eliminated and the search continues on the remaining half, again taking the middle element to compare to the target value. It repeats until the target value is found.

Time complexity: $O(log n)$

Space complexity: $O(1)$

![Binary search visualization](https://upload.wikimedia.org/wikipedia/commons/thumb/c/c1/Binary-search-work.gif/220px-Binary-search-work.gif)

### Linear search

Linear search sequentially checks each element of the array until a match is found or the whole array has been searched.

Time complexity: $O(n)$

Space complexity: $O(1)$

## Sorting algorithms

### Bubble sort

Bubble sort repeatedly steps through the input array element by element, comparing the current element with the one after it, swapping their values if needed. These passes through the array are repeated until no swaps have to be performed during a pass, meaning the array has become fully sorted.

Time complexity: $O(n^2)$

Space complexity: $O(1)$

![Bubble sort visualization](https://upload.wikimedia.org/wikipedia/commons/c/c8/Bubble-sort-example-300px.gif)

### Insertion sort

Insertion sort iterates, consuming one input element each repetition, and grows a sorted output array. At each iteration, it removes one element from the input data, finds the location it belongs within the sorted array, and inserts it there. It repeats unit no input elements remain.

Time complexity: $O(n^2)$

Space complexity: $O(1)$

![Insertion sort visualization](https://upload.wikimedia.org/wikipedia/commons/0/0f/Insertion-sort-example-300px.gif)

### Selection sort

Selection sort divides the input array into two parts: a sorted subarray of elements which is built up from the left to the right at the front of the array, and a subarray of the remaining unsorted elements that occupy the rest of the array. Initially, the sorted subarray is empty and the unsorted subarray is the entire input array. Selection sort poceeds by finding the smallest element in the unsorted subarray, swapping it with the leftmost unsorted element, and moving the subarray boundaries one element to the right.

Time complexity: $O(n^2)$

Space complexity: $O(1)$

![Selection sort visualization](https://upload.wikimedia.org/wikipedia/commons/9/94/Selection-Sort-Animation.gif)