#include <bits/stdc++.h>

using namespace std;

vector<bool> marked(1e6, false);

void sieve(int range)
{
    for (int i = 2; i * i < range; i++)
    {
        if (marked[i] == false) //... Means prime number
        {
            for (int j = i * i; j <= range; j += i)
            {
                marked[j] = true;
            }
        }
    }
}

bool isPrime(int number)
{
    if (number < 2) return false;
    return (marked[number] == false);
}

int main()
{
    sieve(1e5);
    cout << isPrime(269);
}

//... Time Complexity = O(n*log(log(n)))