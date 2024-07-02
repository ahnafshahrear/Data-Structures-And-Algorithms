#include <bits/stdc++.h>

using namespace std;

void insertionSort(vector<int>& numbers) {
    // Number before ith index is already sorted after each iteration
    for (int i = 1; i < numbers.size(); i++) {
        int k = i; // The numbers[k] will be inserted before kth index which is already sorted
        // Inserting numbers[k] before kth index in the appropriate position
        while (k > 0 and numbers[k] < numbers[k - 1]) {
            swap(numbers[k], numbers[k - 1]);
            k--;
        }
    }
} // Time Complexity is O[n*n]

int main() {
    int size;
    cin >> size;

    vector<int> numbers(size);

    for (int i = 0; i < size; i++) {
        cin >> numbers[i];
    }
    insertionSort(numbers);

    for (int i = 0; i < size; i++) {
        cout << numbers[i] << " ";
    }

    return 0;
}
