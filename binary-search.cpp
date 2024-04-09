#include <bits/stdc++.h>

using namespace std;

int binarySearch(vector<int> &numbers, int target)
{
    int low = 0, high = numbers.size() - 1;

    while (high - low > 1)
    {
        int mid = (high + low) / 2;
        if (numbers[mid] == target) return mid;
        else if (numbers[mid] < target) low = mid + 1;
        else high = mid - 1;
    }

    if (numbers[low] == target) return low;
    else if (numbers[high] == target) return high;
    else return -1;
}
//... Time Complexity: O[log(n)]

int main()
{
    int size, target;
    cin >> size >> target;
    vector<int> numbers(size);

    for (int i = 0; i < size; i++)
    {
        cin >> numbers[i];
    }

    cout << binarySearch(numbers, target);

    return 0;
}
