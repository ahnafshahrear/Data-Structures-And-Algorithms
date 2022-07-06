#include <bits/stdc++.h>

using namespace std;

// Author: Ahnaf Shahrear Khan
// Date: 02.06.2k22
// Description: Rabin karp algorithm
// Time Complexity: O(m+n)

#define pb push_back

void rabinKarp(string text, string pattern)
{
    const int base = 256, mod = 269;
    int textSize = text.size(), patternSize = pattern.size();
    int w = 1;
    int textHash = 0, patternHash = 0;

    for (int i = 0; i < patternSize - 1; i++)
    {
        w = (w * base) % mod;
    }

    for (int i = 0; i < patternSize; i++)
    {
        patternHash = (base * patternHash + pattern[i]) % mod;
        textHash = (base * textHash + text[i]) % mod;
    }

    for (int i = 0; i <= textSize - patternSize; i++)
    {
        if (textHash == patternHash) 
        {
            bool flag = true;
            for (int j = 0; j < patternSize; j++)
            {
                if (pattern[j] != text[i + j])
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                cout << "Found at index " << i << "\n";
            }
        }
        if (i < textSize - patternSize)
        {
            textHash = (base * (textHash - text[i] * w) + text[i + patternSize]) % mod;
            if (textHash < 0) textHash += mod;
        }
    }
}

int main()
{
    return 0;
}