#include <bits/stdc++.h>

using namespace std;

void bubbleSort(vector<int>& numbers) {
    // Outer loop shrinks the size of the array from end
    for (int i = 0; i < numbers.size(); i++) {
        // Inner loop moves the largest element at the last index
        for (int j = 1; j < numbers.size() - i; j++) {
            if (numbers[j - 1] > numbers[j]) {
                swap(numbers[j - 1], numbers[j]);
            }
        }
    }
}

int main() {
    int size;
    cin >> size;

    vector<int> numbers(size);

    for (int i = 0; i < size; i++) {
        cin >> numbers[i];
    }

    bubbleSort(numbers);

    for (int i = 0; i < size; i++) {
        cout << numbers[i] << " ";
    }

    return 0;
}
