#include <bits/stdc++.h>

using namespace std;

int binarySearch(vector<int> &numbers, int target)
{
    int low = 0, high = numbers.size() - 1;
    while (low <= high)
    {
        int mid = (high + low) / 2;
        if (numbers[mid] == target) return mid;
        else if (numbers[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}
//... Time Complexity: O[log(n)]

int main()
{
    vector<int> numbers;
    numbers = {24, 31, 74, 101, 143, 254};
    int target = 101;
    cout << binarySearch(numbers, target);
}