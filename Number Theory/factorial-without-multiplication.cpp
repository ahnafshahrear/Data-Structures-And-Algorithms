#include <bits/stdc++.h>

using namespace std;

//... This factorial doesn't use multiplication

//... Call the factorial as factorial(number, number - 1)
int factorial(int number, int x)
{
    if (x == 1) 
    {
        return number;
    }
    int ans = 0;

    for (int k = 1; k <= x; k++)
    {
        ans += number;
    }
    return factorial(ans, x - 1);
}
//... Time Complexity = O[n * (n - 1) / 2]

int main()
{
    int number;
    cin >> number;

    cout << factorial(number, number - 1);
    
    return 0;
}
