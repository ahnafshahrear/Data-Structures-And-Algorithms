#include <bits/stdc++.h>

using namespace std;

double nthRoot(double number, double n)
{
    double eps = 1e-7;
    double low = 1, high = number;
    while (high - low > eps)
    {
        double mid = (high + low) / 2;
        if (pow(mid, n) < number) low = mid;
        else high = mid;
    }
    return low; 
}

int main()
{
    cout << nthRoot(27, 3);
}