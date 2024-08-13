#include <bits/stdc++.h>

using namespace std;

void countingSort(vector<int>& numbers) {
    int largest = 0; //... The largest element of the input

    for (int n : numbers) {
        largest = max(largest, n);
    }
    vector<int> count(largest + 1, 0); //... To store the frequency of each element

    for (int n : numbers) {
        count[n]++;
    }
    for (int i = 1; i < count.size(); i++) { 
        count[i] += count[i - 1]; //... Prefix sum of count array
    }
    vector<int> inputs = numbers;

    for (int i = numbers.size() - 1; i >= 0; i--) {
        count[inputs[i]]--;
        numbers[count[inputs[i]]] = inputs[i];
    }
}
//... Time Complexity is O[n + m] where n and m are the size of input & count array 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int size;
    cin >> size; //... Input the size of the array

    vector<int> numbers(size);

    for (int i = 0; i < size; i++) {
        cin >> numbers[i]; //... Input the numbers
    }

    countingSort(numbers);

    for (int i = 0; i < size; i++) {
        cout << numbers[i] << " ";
    }
    return 0;
}

//... Ahnaf Shahrear Khan, Computer Science & Engineering, University of Rajshahi
//... Gmail: ahnafshahrearkhan@gmail.com
//... GitHub: https://github.com/ahnafshahrear
