#include <bits/stdc++.h>

using namespace std;

void bubbleSort(vector<int> &numbers)
{
    //... Outer loop shrinks the size of the array from end
    for (int i = 0; i < numbers.size(); i++)
    {
        //... Inner loop moves the largest element at the last index
        for (int j = 1; j < numbers.size() - i; j++)
        {
            //... Swap if previous element is greater than current element
            if (numbers[j - 1] > numbers[j])
            {
                swap(numbers[j - 1], numbers[j]);
            }
        }
    }
}
//... Time Complexity: O[n*n] 

int main()
{
    int size;
    vector<int> numbers(size);
    
    //... Call bubbleSort(numbers) to sort "numbers" vector
    bubbleSort(numbers);

    return 0;
}