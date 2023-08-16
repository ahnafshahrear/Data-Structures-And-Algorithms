#include <bits/stdc++.h>

using namespace std;

void selectionSort(vector<int> &numbers)
{
    //... We will find next smallest number for ith index 
    for (int i = 0; i < numbers.size(); i++)
    {
        int index = i;
        //... Checking every index for the number smaller than number[i] 
        for (int j = i; j < numbers.size(); j++)
        {
            if (numbers[j] < numbers[index]) index = j;
        }
        swap(numbers[i], numbers[index]);
    }
}
//... Time Complexity: O[n*n] 

int main()  
{
    int size;
    vector<int> numbers(size);
    
    //... Call selectionSort(numbers) to sort "numbers" vector
    selectionSort(numbers);

    return 0;
}