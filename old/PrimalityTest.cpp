#include <bits/stdc++.h>

using namespace std;

// Author: Ahnaf Shahrear Khan
// Date: 15.06.2k22
// Description: Check if a number is prime or not
// Time Complexity: O(sqrt(n))

bool isPrime(int number)
{
    if (number == 2) return true;
    else if (!(number % 2) or number < 2) return false;

    int sq = sqrt(number) + 1;
    
    for (int i = 3; i <= sq; i += 2)
    {
        if (number % i == 0) return false;
    }
    return true;
}

int main()
{
    int number;
    isPrime(number);
}