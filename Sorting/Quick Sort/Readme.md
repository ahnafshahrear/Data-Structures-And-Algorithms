# Quick Sort
*[Ahnaf Shahrear Khan](https://github.com/ahnafshahrear) - Computer Science & Engineering, University of Rajshahi*
- **QuickSort is a sorting algorithm based on the Divide and Conquer algorithm that picks an element as a pivot and partitions the given array around the picked pivot by placing the pivot in its correct position in the sorted array.**



## Algorithm
- **Select a pivot element from the array.**
- **Partition the array into two sub-arrays: elements less than the pivot on the left and elements greater than the pivot on the right.**
- **The pivot is now in its correct position in the sorted array.**
- **Recursively apply the same process to the left and right sub-arrays until the entire array is sorted.**



## Time Complexity
- **Time Complexity is `O[n*log(n)]` where `n` is the size of the array.**



## Interview Questions 
- **It has a worst-case time complexity of `O[n^2]` which occurs when the pivot is chosen poorly.**
- **It is not a stable sort, meaning that if two elements have the same key, their relative order will not be preserved in the sorted output in case of quick sort**
- **Quick sort algorithm is an in-place algorithm.**
