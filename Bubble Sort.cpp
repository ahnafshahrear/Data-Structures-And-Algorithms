#include<bits/stdc++.h>

using namespace std;

// Author: Ahnaf Shahrear Khan
// Date: 7.06.2k22
// Description: Bubble sort algorithm
// Time Complexity: O(n*n)

vector<int> nums;

void bubbleSort()
{
    int size = nums.size();
    bool swapped;

    for (int i = 0; i < size; i++)
    {
        swapped = false;
        for (int j = 0; j < size - i; j++)
        {
            if (nums[j + 1] < nums[j])
            {
                swapped = true;
                swap(nums[j], nums[j + 1]);
            }
        }
        
        if (!swapped) 
        {
            break;
        }
    }
}

int main()
{
    bubbleSort();
}