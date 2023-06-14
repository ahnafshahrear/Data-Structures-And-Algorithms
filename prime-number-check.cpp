#include <bits/stdc++.h>

using namespace std;

bool isPrime(int number)
{
    if (number < 2) return false;
    for (int i = 2; i * i <= number; i++)
    {
        if (number % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    isPrime(269) ? cout << "The number is prime" : cout << "The number isn't prime";
}

//... Check whether a number is prime or not
//... Time Complexity = o(√n)