#include <bits/stdc++.h>

using namespace std;

vector<int> dp(1e5, -1);

int longestIncreasingSubsequence(vector<int> &numbers, int index)
{
    if (dp[index] != -1) return dp[index];
    int ans = 0;
    for (int i = 0; i < index; i++)
    {
        if (numbers[i] < numbers[index]) ans = max(longestIncreasingSubsequence(numbers, i), ans);
    }
    return dp[index] = ans + 1;
}

int main()
{
    vector<int> numbers; 
    numbers = {31, 6, 47, 25, 93, 101};
    int longest = 0;
    for (int index = 0; index < numbers.size(); index++)
    {
        longest = max(longestIncreasingSubsequence(numbers, index), longest);
    }
    cout << longest;
}