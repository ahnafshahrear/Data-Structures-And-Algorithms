#include <bits/stdc++.h>

using namespace std;

void bubbleSort(vector<int>& numbers) {
    //... Outer loop shrinks the size of the array from end
    for (int i = 0; i < numbers.size(); i++) {
        //.... Inner loop moves the largest element at the current last index
        for (int j = 1; j < numbers.size() - i; j++) {
            if (numbers[j - 1] > numbers[j]) {
                swap(numbers[j - 1], numbers[j]);
            }
        }
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

    bubbleSort(numbers);

    for (int i = 0; i < size; i++) {
        cout << numbers[i] << " ";
    }
    return 0;
}

//... Ahnaf Shahrear Khan, Computer Science & Engineering, University of Rajshahi
//... Gmail: ahnafshahrearkhan@gmail.com
//... GitHub: https://github.com/ahnafshahrear
