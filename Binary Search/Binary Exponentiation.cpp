#include <bits/stdc++.h>

using namespace std;

//... Function to calculate the power of a number using binary exponentiation
double binaryExponentiation(double number, int power) { 
    if (!power) { //... number ^ 0 = 1
        return 1;
    } else if (power < 0) { //... number ^ -(power) is equal to 1 / (number ^ power)
        return 1 / binaryExponentiation(number, -power);
    } else if (power & 1) { 
        return number * binaryExponentiation(number * number, power / 2);
    } else {
        return binaryExponentiation(number * number, power / 2);
    }
}
//... Time Complexity is O[log(n)] where n is the absolute value of the power

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int number, power;
    cin >> number >> power; //... Input the number & the power

    cout << binaryExponentiation(number, power);

    return 0;
}

//... Ahnaf Shahrear Khan, Computer Science & Engineering, University of Rajshahi
//... Gmail: ahnafshahrearkhan@gmail.com
//... GitHub: https://github.com/ahnafshahrear
