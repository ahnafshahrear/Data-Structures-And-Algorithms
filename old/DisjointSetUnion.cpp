#include <bits/stdc++.h>

using namespace std;

// ahnafshahrearkhan@gmail.com

#define dsuSize (int)1e4 // Size of the disjoint set

int parent[dsuSize]; // Store every value's set parent/representative

void MakeSet(int value) 
{
    parent[value] = value; 
}

int Find(int value)
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

bool IsFriend(int value1, int value2)
{
    return Find(value1) == Find(value2); 
}