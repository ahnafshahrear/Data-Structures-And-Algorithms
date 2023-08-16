#include <bits/stdc++.h>

using namespace std;

vector<int> numbers(1e5), temp(1e5);

void mergeSort(int low, int high)
{
    if (low == high) //... That means only 1 element & already sorted
    {
        return;
    }

    int mid = (low + high) / 2;

    mergeSort(low, mid);
    mergeSort(mid + 1, high);

    for (int i = low, j = mid + 1, k = low; k <= high; k++)
    {
        if (i == mid + 1) temp[k] = numbers[j++]; //... That means 1st segment is finished
        else if (j == high + 1) temp[k] = numbers[i++]; //... That means 2nd segment is finished
        else if (numbers[i] < numbers[j]) temp[k] = numbers[i++];
        else temp[k] = numbers[j++];
    }

    //... Copying the temporary vector into main numbers vector
    for (int k = low; k <= high; k++)
    {
        numbers[k] = temp[k];
    }
}
//... Time Complexity: O[n*log(n)] 

int main()
{
    int size;

    //... Call mergeSort(a, b) to sort numbers[a...b]
    mergeSort(0, size - 1); 

    return 0;
}