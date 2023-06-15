#include <bits/stdc++.h>

using namespace std;

vector<bool> marked(1e5, false);

void sieve(int range)
{
    for (int x = 2; x * x < range; x++)
    {
        if (marked[x] == false) //... Number "x" is a prime number
        {
            for (int k = x * x; k <= range; k += x)
            {
                marked[k] = true;
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
    sieve(1e5); //... Finds all the prime numbers from 1 to 100000
    isPrime(269) ? cout << "The number is prime" : cout << "The number isn't prime";
}

//... Finds all the prime numbers from 1 to "range"
//... Time Complexity = O(n*log(log(n)))