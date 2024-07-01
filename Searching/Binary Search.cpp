#include <bits/stdc++.h>

using namespace std;

int binarySearch(vector<int>& numbers, int target) {
    int low = 0, high = numbers.size() - 1;

    while (high - low > 1) {
        int mid = (high + low) / 2;

        if (numbers[mid] == target) {
            return mid;
        } else if (numbers[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }   
    }

    if (numbers[low] == target) {
        return low;
    } else if (numbers[high] == target) {
        return high;
    } else {
        return -1;
    }
}

int main() {
    vector<int> numbers = {1, 3, 7, 12, 27, 35, 47, 54, 69, 71};

    int target = 12;

    cout << binarySearch(numbers, target);

    return 0;
}
