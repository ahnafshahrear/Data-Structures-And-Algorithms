# Counting Sort
*[Ahnaf Shahrear Khan](https://github.com/ahnafshahrear) - Computer Science & Engineering, University of Rajshahi*
- **Counting Sort is a non-comparison-based sorting algorithm where the basic idea is to count the frequency of each distinct element in the input array & use that information to place the elements in their correct sorted positions.**



## Algorithm
- **Determine the range of the elements from the input array.**
- **Create a count array where each index corresponds to an element in the input array & the value at each index represents the frequency of that element.**
- **Accumulate the counts to determine the positions of elements in the sorted array.**
- **Traverse the input array, placing each element at its correct position in the output array based on the accumulated counts.**



## Time Complexity
- **Time Complexity is `O[m + n]` where `m` & `n` are the size of the input array & the count array.**



## Interview Questions 
- **Counting sort is not an In-place sorting algorithm, It uses extra space for sorting the array elements.**
- **It is a stable sorting algorithm, meaning that elements with the same key value maintain their relative order in the sorted output.**
- **Counting sort generally performs faster than all comparison-based sorting algorithms, such as merge sort & quicksort, if the range of input is of the order of the number of inputs.**
- **Counting sort doesn’t work on decimal values.**
- **Counting sort is inefficient if the range of values to be sorted is very large.**
- **It is a commonly used algorithm for cases where we have a limited range of items. For example, sort students by grades, sort a events by time, days, months, years, etc**
