#include <bits/stdc++.h>

using namespace std;

#define on(x) (marked[x / 64] & (1 << ((x % 64) / 2)))
#define mark(x) marked[x / 64] |= (1 << ((x % 64) / 2))

int size = 1e6; //... Max possible total prime numbers
vector<int> marked(size / 64 + 1, 0); 
//... int is 32-bit but we are dividing by 64 because we are ignoring even 

void sieve(int range)
{
    for (int x = 3; x * x <= range; x += 2)
    {
        if (!on(x)) //... Number "x" is a prime number
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
    sieve(1e5);
    cout << isPrime(269);
}

//... Time Complexity = o(n*log(log(n)))