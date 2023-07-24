#include <bits/stdc++.h>

using namespace std;

int binarySearch(vector<int> x, int target)
{
    int low = 0, high = x.size() - 1;
    while (low <= high)
    {
        int mid = (high + low) / 2;
        if (x[mid] == target) return mid;
        else if (x[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}
//... Time Complexity: O[log(n)]

int lowerBound(vector<int> x, int target)
{
    int low = 0, high = x.size() - 1;
    while (high - low > 1)
    {
        int mid = (high + low) / 2;
        if (x[mid] < target) low = mid + 1;
        else high = mid;
    }
    if (x[low] >= target) return low;
    else if (x[high] >= target) return high;
    else return -1;
}
//... Time Complexity: O[log(n)]

int upperBound(vector<int> x, int target)
{
    int low = 0, high = x.size() - 1;
    while (high - low > 1)
    {
        int mid = (high + low) / 2;
        if (x[mid] <= target) low = mid + 1;
        else high = mid;
    }
    if (x[low] > target) return low;
    else if (x[high] > target) return high;
    else return -1;
}
//... Time Complexity: O[log(n)]

int main()
{
    vector<int> numbers = {1, 4, 7, 69, 74};
    int target = 7;
    cout << binarySearch(numbers, target);
}