#include <bits/stdc++.h>

using namespace std;

void selectionSort(vector<int>& numbers) {
    //... The numbers before i'th position is already sorted
    //... The next smallest number will be stored in the i'th position
    for (int i = 0; i < numbers.size() - 1; i++) {
        int minIndex = i; //... Index of the next smallest number
        for (int j = i + 1; j < numbers.size(); j++) {
            if (numbers[j] < numbers[minIndex]) {
                minIndex = j;
            }
        }
        swap(numbers[i], numbers[minIndex]);
    }
}
//... Time Complexity is O[n^2] where n is the size of the array 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int size;
    cin >> size; //... Input the size of the array

    vector<int> numbers(size);

    for (int i = 0; i < size; i++) {
        cin >> numbers[i]; //... Input the numbers
    }

    selectionSort(numbers);

    for (int i = 0; i < size; i++) {
        cout << numbers[i] << " ";
    }
    return 0;
}

//... Ahnaf Shahrear Khan, Computer Science & Engineering, University of Rajshahi
//... Gmail: ahnafshahrearkhan@gmail.com
//... GitHub: https://github.com/ahnafshahrear
