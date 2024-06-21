#include <bits/stdc++.h>

using namespace std;

bool isPrime(int number) {
    if (number <= 1) {
        return false;
    }

    for (int n = 2; n * n <= number; n++) {
        if (number % n == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int number;
    cin >> number;

    cout << isPrime(number);

    return 0;
}
