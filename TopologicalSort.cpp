#include <bits/stdc++.h>

using namespace std;

// ahnafshahrearkhan@gmail.com

typedef long long int int64;
typedef unsigned long long int uint64;

#define pb push_back

int node, edge; // Total number of nodes & edges
vector<int> order; // Store sorted nodes

void topologicalSort()
{
    cin >> node >> edge;
    vector<int> graph[node], inDeg(node, 0);

    for (int i = 0; i < edge; i++)
    {
        int first, second; // Second node is dependent to first node
        cin >> first >> second;
        graph[first].pb(second); // Adding second node to first node's adjacency list
        inDeg[second]++; // Second node's in-degree is increased
    }

    queue<int> task; // Store nodes with no in-degree
    for (int i = 0; i < node; i++)
    {
        if (!inDeg[i]) // Zero in-degree means no dependency
        {
            task.push(i);
        }
    }

    while (!task.empty())
    {
        int node = task.front();
        task.pop();
        order.pb(node); // Add the first node in the sorted list & remove from queue

        for (auto x: graph[node]) // Traverse all the adjacency nodes 
        {
            inDeg[x]--; // Decrease the in-degree
            if (!inDeg[x]) // Add the node in queue if the in-degree is zero
            {
                task.push(x);
            }
        }
    }

    for (auto node: order) // Print the topological sorted list
    {
        cout << node << "\n";
    }
}

int main()
{
    topologicalSort();
    return 0;
}