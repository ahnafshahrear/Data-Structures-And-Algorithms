#include<bits/stdc++.h>

using namespace std;

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
        if (!swapped) break;
    }
}

int main()
{
    bubbleSort();
    return 0;
}