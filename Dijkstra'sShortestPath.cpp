#include <bits/stdc++.h>

using namespace std;

// Author: Ahnaf Shahrear Khan
// Date: 15.06.2k22
// Description: Find single source shortest path
// Time Complexity: O(V+E*logV)

typedef long long int int64;
typedef pair<int64, int64> int64pair;

#define pb push_back

const int64 inf = 1e17;
int64 vertex, edge; // Total number of vertex and edges
vector<vector<int64pair>> adj(1e5 + 1); // Adjacency list with weights
int source = 1;

void dijkstra()
{
    priority_queue<int64pair, vector<int64pair>, greater<int64pair>> pq; // Store updated distance and node  
    pq.push({0, source}); 

    vector<int64> dist(1e5 + 1, inf), sources(1e5 + 1); // Store shortest distance & sources
    dist[source] = 0;

    vector<bool> visited(1e5 + 1, false);

    while (!pq.empty())
    {
        int64 vtx = pq.top().second; // Top vertex of queue 
        pq.pop();

        if (visited[vtx]) 
        {
            continue; // If visited, dont process
        }
        visited[vtx] = 1; // Make visited

        for (auto x : adj[vtx])
        {
            int64 v = x.first; // Node is stored on first element of pair
            int64 weight = x.second; // Weight is stored on second element of pair

            if ((dist[vtx] + weight) < dist[v]) // Going through the node from top of queue
            {
                dist[v] = dist[vtx] + weight; // Update distance
                pq.push({dist[v], v}); // If new distance is smaller then add the node to the priority queue
                sources[v] = vtx; // Update it's source
            }
        }
    }
    if (dist[vertex] == inf) // If distance is infinity then there is no path
    {
        cout << "-1";
        return;
    }

    vector<int64> path{vertex}; // Store path nodes

    int index = vertex;
    while (true) // Finding path nodes
    {
        index = sources[index];
        path.pb(index);
        
        if (index == 1)
        {
            break;
        }
    }
    
    for (int k = path.size() - 1; k >= 0; k--) // Print the path
    {
        cout << path[k] << " ";
    }
}

int main()
{
    cin >> vertex >> edge;
    for (int i = 0; i < edge; i++)
    {
        int n1, n2, w;
        cin >> n1 >> n2 >> w;
        adj[n1].pb(make_pair(n2, w)); // Both node's adjacency list is updated
        adj[n2].push_back(make_pair(n1, w)); // Undirected graph
    }
    dijkstra();
}