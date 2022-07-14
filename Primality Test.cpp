#include <bits/stdc++.h>

using namespace std;

bool isPrime(int number)
{
    if (number == 2) return true;
    else if (!(number % 2) or number < 2) return false;
    int sq = sqrt(number) + 1;
    for (int i = 3; i <= sq; i += 2)
    {
        if (!(number % i)) return false;
    }
    return true;
}

int main()
{
    return 0;
}