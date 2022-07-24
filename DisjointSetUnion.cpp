#include <bits/stdc++.h>

using namespace std;

typedef long long int int64;
typedef unsigned long long int uint64;

#define pb push_back
#define dsuSize 100000 // Size of the disjoint set

int parent[dsuSize]; // Store every values representative

void MakeSet(int value) // Initially make a value as it's own parent
{
    parent[value] = value; 
}

int Find(int value) // Find the parent
{
    if (value == parent[value])
    {
        return value;
    }
    return parent[value] = Find(parent[value]);
}

void Union(int value1, int value2) // Union of two sets
{
    int p1 = Find(value1), p2 = Find(value2);
    if (p1 != p2)
    {
        parent[p2] = p1; // Elements of p2 are now elements of p1 
    }
}

bool IsFriend(int value1, int value2) // Check if both belongs in the same set
{
    return Find(value1) == Find(value2);
}

int main()
{
    return 0;
}