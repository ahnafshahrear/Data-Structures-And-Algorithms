#include <bits/stdc++.h>

using namespace std;

//... Function to calculate the square root of a given number using binary search
double squareRoot(double number) {
    double eps = 1e-7; //... Accuracy of the result
    double low = 0, high = number;

    while (high - low > eps) {
        double mid = (low + high) / 2;
        if (mid * mid < number) { //... Square Root must be greater
            low = mid;
        } else { //... Square Root must be smaller than mid
            high = mid;
        }
    }
    return high;
}
//... Time Complexity is O[log(number/eps)]

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int number;
    cin >> number; //... Input the number

    cout << squareRoot(number);

    return 0;
}

//... Ahnaf Shahrear Khan, Computer Science & Engineering, University of Rajshahi
//... Gmail: ahnafshahrearkhan@gmail.com
//... GitHub: https://github.com/ahnafshahrear
