# Random Algorithms

### QuickSort
A divide and conquer algorithm uses partition around a pivot to divide the array into two parts and then sorts recursively. The worst-case time complexity is O(n^2).

#### Randomized Quicksort
Worst case expected running time O(nlogn)

#### Linear median finding Quicksort
If the median finding is implemented in O(n) time, Quicksort becomes O(nlogn).

#### Paranoid Quicksort
Since Linear median finding Quicksort is practically not fast enough, we can use paranoid quicksort. This paranoid algorithm checks if pivot selection is good enough, if not, it partitions again. Used middle pivot selection for practical performance since array can be partitioned more than once, it is more likely to have a good pivot in the middle. If theoretical performance is more important, randomized pivot selection can be used in this implementation.



