#include <bits/stdc++.h>

using namespace std;

vector<int> primes; //... Preload the primes once at the beginning
vector<bool> marked(1e5, false);

void sieve(int range)
{
    for (int x = 2; x <= range; x++)
    {
        if (marked[x] == false) //... Number "x" is a prime number
        {
            primes.push_back(x);
            for (int k = x * x; k <= range; k += x)
            {
                marked[k] = true;
            }
        }
    }
}

int countDivisor(int number)
{
    int divisor = 1;
    for (int i = 0; i < primes.size(); i++)
    {
        if (number % primes[i] == 0)
        {
            int count = 0; //... Number of times "primes[i]" divides "number" 
            while (number % primes[i] == 0)
            {
                number /= primes[i];
                count++;
            }
            divisor = divisor * (count + 1);
        }
    }
    return divisor;
}

int main()
{
    sieve(1e5); //... Finds all the prime numbers from 1 to 100000
    cout << countDivisor(36);
}

//... Finds the total number of divisors of a number
//... Time Complexity = O(log(n))