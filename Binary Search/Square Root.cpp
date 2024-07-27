#include <bits/stdc++.h>

using namespace std;

double squareRoot(double number) {
    double eps = 1e-7;
    double low = 0, high = number;

    while (high - low > eps) {
        double mid = (low + high) / 2;
        if (mid * mid < number) {
            low = mid;
        } else {
            high = mid;
        }
    }
    return high;
}

int main() {
    cout << squareRoot(247);

    return 0;
}
