#include <bits/stdc++.h>

using namespace std;

void mergeSort(vector<int>& numbers, int low, int high) {
    if (low == high) {
        return; //... There is only a single element which is sorted 
    }
    int mid = (high + low) / 2; //... The midpoint

    mergeSort(numbers, low, mid); //... Sort the left half
    mergeSort(numbers, mid + 1, high); //... Sort the right half

    vector<int> temp(high + 1); //... Temporary vector to store the merged result

    //... Merge the two sorted halves
    for (int i = low, j = mid + 1, k = low; k <= high; k++) {
        if (i == mid + 1) { //... Left half completed
            temp[k] = numbers[j++];
        } else if (j == high + 1) { //... Right half completed
            temp[k] = numbers[i++];
        } else if (numbers[i] <= numbers[j]) { //... Left element is smaller
            temp[k] = numbers[i++];
        } else { //... Right element is smaller
            temp[k] = numbers[j++];
        }
    }
    
    //... Copy the merged result back into the original vector
    for (int k = low; k <= high; k++) {
        numbers[k] = temp[k];
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

    mergeSort(numbers, 0, size - 1);

    for (int i = 0; i < size; i++) {
        cout << numbers[i] << " ";
    }
    return 0;
}

//... Ahnaf Shahrear Khan, Computer Science & Engineering, University of Rajshahi
//... Gmail: ahnafshahrearkhan@gmail.com
//... GitHub: https://github.com/ahnafshahrear
