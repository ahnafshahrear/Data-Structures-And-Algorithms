#include <bits/stdc++.h>

using namespace std;

vector<int> cache(1e5, -1);

int longestIncreasingSubsequence(int index, vector<int>& numbers) {
    if (cache[index] != -1) {
        return cache[index];
    } 
    int result = 1;

    for (int i = 0; i < index; i++) {
        if (numbers[i] < numbers[index]) {
            result = max(longestIncreasingSubsequence(i, numbers) + 1, result);
        }
    }
    return cache[index] = result;
}

int main() {
    int size;
    cin >> size;

    vector<int> numbers(size);

    for (int i = 0; i < size; i++) {
        cin >> numbers[i];
    }
    int length = 0;

    // Finding the length of the longest increasing subsequence ending at the ith index
    for (int i = 0; i < size; i++) {
        length = max(longestIncreasingSubsequence(i, numbers), length);
    }
    cout << length;

    return 0;
}
