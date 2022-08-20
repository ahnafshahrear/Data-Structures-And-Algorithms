#include <bits/stdc++.h>

using namespace std;

// Ahnaf Shahrear Khan - RuCse27

// Calculate the number of co-primes of n which are less then n
// Co-prime means no common divisor

// If p1, p2, p3... are primes factors of n, phi(n) = n * (1 - 1/p1) * (1 - 1/p2) * (1 - 1/p3)... 
// If p is prime, then phi(p) = p - 1


vector<int> phi(1e5 + 1), mark(1e5 + 1, 0);

// Calculate phi for up to size
void sievePhi(int size)
{
    for (int x = 0; x <= size; x++) // Initialization
    {
        phi[x] = x;
    }
    for (int p = 2; p <= size; p++)
    {
        // If prime number
        if (!mark[p])
        {
            for (int j = p; j <= size; j += p) // Primes multiples
            {
                mark[j] = 1;
                phi[j] = phi[j] / p * (p - 1); // This means n * (1 - 1/p)
            }
        }
    }
}

// Calculate phi for a single value
int singlePhi(int value)
{
    int ans = value;
    for (int p = 2; p * p <= value; p++)
    {
        if (value % p == 0) // Means p is a prime
        {
            while (value % p == 0) // Eliminating all occurrence of p 
            {
                value /= p;
            }
            ans -= ans / p; // This means n * (1 - 1/p)
        }
    }
    // Means a prime greater than sqrt(value)
    if (value > 1)
    {
        ans -= ans / value;
    }
    return ans;
}

int main()
{
    return 0;
}
