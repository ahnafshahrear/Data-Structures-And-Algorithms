#include <bits/stdc++.h>

using namespace std;

int lowerBound(vector<int> &numbers, int target)
{
    int low = 0, high = numbers.size() - 1;
    while (high - low > 1)
    {
        int mid = (high + low) / 2;
        if (numbers[mid] < target) low = mid + 1;
        else high = mid;
    }
    if (numbers[low] >= target) return low;
    else if (numbers[high] >= target) return high;
    else return -1;
}
//... Time Complexity: O[log(n)]

int main()
{
    vector<int> numbers;
    numbers = {24, 31, 56, 74, 96, 101};
    int target = 75;
    cout << lowerBound(numbers, target);
}