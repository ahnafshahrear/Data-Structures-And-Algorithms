#include <bits/stdc++.h>

using namespace std;

void insertionSort(vector<int> &numbers)
{
    //... Numbers before ith index is sorted each time
    for (int i = 1; i <= numbers.size(); i++)
    {
        int numberNow = numbers[i];
        int k = i - 1; 
        //... Finding the appropiate index for the current number[i]
        while (k >= 0 and numberNow < numbers[k])
        {
            numbers[k + 1] = numbers[k];
            k--;
        }
        numbers[++k] = numberNow; 
    }
}
//... Function Parameter: vector<int> of some numbers
//... This function sorts the original vector
//... Time Complexity: O[n*n] 