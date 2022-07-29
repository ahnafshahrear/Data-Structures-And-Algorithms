#include <bits/stdc++.h>

using namespace std;

typedef long long int int64;
typedef pair<int64, int64> int64pair;

#define pb push_back

const int64 inf = 1e17;
int64 vertex, edge;
vector<vector<int64pair>> adj(1e5 + 1);
int source = 1;

void dijkstra() 
{
    priority_queue<int64pair, vector<int64pair>, greater<int64pair>> pq;
    pq.push({0, source}); 

    vector<int64> dist(1e5 + 1, inf), sources(1e5 + 1);
    dist[source] = 0;

    vector<bool> visited(1e5 + 1, false);

    while (!pq.empty())
    {
        int64 vtx = pq.top().second;
        pq.pop();

        if (visited[vtx]) 
        {
            continue;
        }
        visited[vtx] = 1;

        for (auto x : adj[vtx])
        {
            int64 v = x.first;
            int64 weight = x.second; 

            if ((dist[vtx] + weight) < dist[v])
            {
                dist[v] = dist[vtx] + weight; 
                pq.push({dist[v], v}); 
                sources[v] = vtx; 
            }
        }
    }
    if (dist[vertex] == inf) 
    {
        cout << "-1";
        return;
    }

    vector<int64> path{vertex}; 

    int index = vertex;
    while (true) 
    {
        index = sources[index];
        path.pb(index);
        
        if (index == 1)
        {
            break;
        }
    }
    
    for (int k = path.size() - 1; k >= 0; k--) 
    {
        cout << path[k] << " ";
    }
}

int main()
{
    return 0;
}