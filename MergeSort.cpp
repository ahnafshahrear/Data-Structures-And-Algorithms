#include <bits/stdc++.h>

using namespace std;

// Author: Ahnaf Shahrear Khan
// Date: 02.06.2k22
// Description: Merge sort algorithm
// Time Complexity: O(n*logn)

const int size = 1e5;
int numbers[size], temp[size];

void mergeSort(int lower, int upper)
{
    if (lower == upper)
    {
        return;
    }
    int mid = (lower + upper) / 2;

    mergeSort(lower, mid);
    mergeSort(mid + 1, upper);

    int i = lower, j = mid + 1, k = lower;
    while (k++ <= upper)
    {
        if (i == mid + 1) temp[k - 1] = numbers[j++];
        else if (j == upper + 1) temp[k - 1] = numbers[i++];
        else if (numbers[i] < numbers[j]) temp[k - 1] = numbers[i++];
        else temp[k - 1] = numbers[j++];
    }

    for (i = lower; i <= upper; i++)
    { 
        numbers[i] = temp[i];
    }
}

int main()
{
    int lower, upper;
    mergeSort(lower, upper);
}