#include <bits/stdc++.h>

using namespace std;

void insertionSort(vector<int>& numbers) {
    //... Numbers before the ith index are already sorted
    for (int i = 1; i < numbers.size(); i++) {
        int k = i;
        //... Inserting numbers[k] before kth index in the appropriate position
        while (k > 0 and numbers[k] < numbers[k - 1]) {
            swap(numbers[k], numbers[k - 1]);
            k--;
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

    insertionSort(numbers);

    for (int i = 0; i < size; i++) {
        cout << numbers[i] << " ";
    }
    return 0;
}

//... Ahnaf Shahrear Khan, Computer Science & Engineering, University of Rajshahi
//... Gmail: ahnafshahrearkhan@gmail.com
//... GitHub: https://github.com/ahnafshahrear
