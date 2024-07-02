#include <bits/stdc++.h>

using namespace std;

void selectionSort(vector<int>& numbers) {
    // The numbers before ith position will be sorted after each iteration
    // Next smallest number will be stored in the ith position
    for (int i = 0; i < numbers.size() - 1; i++) {
        int minIndex = i; // Index of the next smallest number
        for (int j = i + 1; j < numbers.size(); j++) {
            if (numbers[j] < numbers[minIndex]) {
                minIndex = j;
            }
        }
        swap(numbers[i], numbers[minIndex]);
    }
} // Time Complexity is O[n*n]

int main() {
    int size;
    cin >> size;

    vector<int> numbers(size);

    for (int i = 0; i < size; i++) {
        cin >> numbers[i];
    }
    selectionSort(numbers);

    for (int i = 0; i < size; i++) {
        cout << numbers[i] << " ";
    }
    return 0;
}
