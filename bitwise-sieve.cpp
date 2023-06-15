#include <bits/stdc++.h>

using namespace std;

#define offset(x) (1 << ((x % 64) / 2))
#define on(x) (marked[x / 64] & offset(x))
#define mark(x) (marked[x / 64] |= offset(x))

int size = 1e6; //... Max possible total prime numbers
vector<int> marked(size / 64 + 1, 0); 
//... int is 32-bit but we are dividing by 64 because we are ignoring even 

void sieve(int range)
{
    for (int x = 3; x * x <= range; x += 2)
    {
        if (on(x) == 0) //... Number "x" is a prime number
        {
            for (int k = x * x; k <= range; k += x + x)
            {
                mark(k);
            }
        }
    }
}

bool isPrime(int number)
{
    return number > 1 and (number == 2 or ((number & 1) and !on(number)));
}

int main()
{
    sieve(1e5); //... Finds all the prime numbers from 1 to 100000
    isPrime(269) ? cout << "The number is prime" : cout << "The number isn't prime";
}

//... Finds all the prime numbers from 1 to "range"
//... Time Complexity = o(n*log(log(n)))