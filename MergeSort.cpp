#include <bits/stdc++.h>

using namespace std;

const int size = 1e5; // Array size
int numbers[size], temp[size];

void mergeSort(int lower, int upper) // Segment to be sorted
{
    if (lower == upper) // Single element
    {
        return;
    }
    int mid = (lower + upper) / 2; // Middle pointer 

    mergeSort(lower, mid);
    mergeSort(mid + 1, upper);

    int i = lower, j = mid + 1, k = lower;
    while (k++ <= upper) // Merging the two sorted list into temp
    {
        if (i == mid + 1) // Lower part is already taken
        {
            temp[k - 1] = numbers[j++]; // Taking the upper part and incrementing pointer
        } 
        else if (j == upper + 1) // Upper part is already taken
        {
            temp[k - 1] = numbers[i++]; // Taking every lower part value
        }
        else if (numbers[i] < numbers[j])
        {
            temp[k - 1] = numbers[i++];
        }
        else temp[k - 1] = numbers[j++];
    }

    for (i = lower; i <= upper; i++) 
    { 
        numbers[i] = temp[i]; 
        // Copying the values of temp int the original array 
    }
}

int main()
{
    return 0;
}