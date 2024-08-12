#include <bits/stdc++.h>

using namespace std;

int partition(vector<int>& numbers, int start, int end) {
    int pivot = numbers[end]; //... Chose the pivot
    int i = start - 1; //... Index of the smaller elements found so far

    for (int j = start; j < end; j++) {
        if (numbers[j] < pivot) {
            swap(numbers[++i], numbers[j]);
        }
    }
    swap(numbers[++i], numbers[end]);
    
    return i; //... Everything before i'th index is smaller & after i'th index is larger
}
void quickSort(vector<int>& numbers, int start, int end) {
    if (start < end) {
        int pi = partition(numbers, start, end);

        quickSort(numbers, start, pi - 1);
        quickSort(numbers, pi + 1, end);
    }
}
//... Time Complexity is O[n*log(n)] where n is the size of the array 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int size;
    cin >> size; //... Input the size of the array

    vector<int> numbers(size);

    for (int i = 0; i < size; i++) {
        cin >> numbers[i]; //... Input the numbers
    }

    quickSort(numbers, 0, size - 1);

    for (int i = 0; i < size; i++) {
        cout << numbers[i] << " ";
    }
    return 0;
}

//... Ahnaf Shahrear Khan, Computer Science & Engineering, University of Rajshahi
//... Gmail: ahnafshahrearkhan@gmail.com
//... GitHub: https://github.com/ahnafshahrear
