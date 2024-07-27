#include <bits/stdc++.h>

using namespace std;

//... Returns the first index where the value is not less than the target, or -1 if no such element exists
int lowerBound(vector<int>& numbers, int target) {
    int low = 0, high = numbers.size() - 1;

    while (high - low > 1) {
        int mid = (high + low) / 2;

        if (numbers[mid] < target) { //... The lower bound can't be on the left side
            low = mid + 1;
        } else { //... The lower bound can't be on the right side
            high = mid;
        }
    }

    if (numbers[low] >= target) {
        return low;
    } else if (numbers[high] >= target) {
        return high;
    } else {
        return -1;
    }
}
//... Time Complexity is O[log(n)] where n is the size of the numbers array 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int size;
    cin >> size; //... Input the size of the array

    vector<int> numbers(size);

    for (int i = 0; i < size; i++) {
        cin >> numbers[i]; //... Input the numbers
    }

    int target;
    cin >> target; //... Input the target number to search for

    cout << lowerBound(numbers, target);

    return 0;
}

//... Ahnaf Shahrear Khan, Computer Science & Engineering, University of Rajshahi
//... Gmail: ahnafshahrearkhan@gmail.com
//... GitHub: https://github.com/ahnafshahrear
