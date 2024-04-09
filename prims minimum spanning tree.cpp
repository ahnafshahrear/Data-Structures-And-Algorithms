#include <bits/stdc++.h>

using namespace std;

int nextNode(vector<int> &weights, vector<bool> &used)
{
    int node, minWeight = INT_MAX;
    for (int n = 1; n < weights.size(); n++)
    {
        if (!used[n] and weights[n] < minWeight)
        {
            minWeight = weights[n];
            node = n;
        }
    }
    return node;
}

int primsMinSpanningTree(vector<vector<pair<int, int>>> &graph)
{
    int size = graph.size();
    vector<int> parent(size), weights(size, INT_MAX);
    vector<bool> used(size, false);

    weights[0] = 0; parent[0] = -1;

    int cost = 0;
    int counter = size - 1;
    while (counter--)
    {
        int node = nextNode(weights, used);
        used[node] = true;
        cost += weights[node];

        for (auto n: graph[node])
        {
            if (!used[n.first] and n.second < weights[n.first])
            {
                parent[n.first] = node;
                weights[n.first] = n.second;
            }
        }
    }
    return cost;
}