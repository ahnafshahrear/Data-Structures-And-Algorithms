#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
} 

int main() {
    int number1, number2;
    cin >> number1 >> number2;
    cout << gcd(number1, number2);

    return 0;
}
