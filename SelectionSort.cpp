#include <bits/stdc++.h>

using namespace std;

// Author: Ahnaf Shahrear Khan
// Date: 18.02.2k23
// Description: Selection sort algorithm
// Time Complexity: O(n*n)

vector<int> numbers;

void selectionSort()
{
    int size = numbers.size();
    
    for (int i = 0; i < size; i++)
    {
        int index = i;
        for (int j = i + 1; j < size; j++)
        {
            if (numbers[j] < numbers[index])
            {
                index = j;
            }
        }
        swap(numbers[i], numbers[index]);
    }
}

int main()
{
    selectionSort();
    return 0;
}   