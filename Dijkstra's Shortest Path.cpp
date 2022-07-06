#include <bits/stdc++.h>

using namespace std;

typedef long long int int64;
typedef unsigned long long uint64;
typedef pair<uint64, uint64> uint64pair;

#define pb push_back

const uint64 inf = 1e17;
uint64 vertex, edge;
vector<vector<uint64pair>> adj(1e5 + 1);
int source = 1;

void dijkstra()
{
    priority_queue<uint64pair, vector<uint64pair>, greater<uint64pair>> pq;
    vector<uint64> dist(1e5 + 1, inf), sources(1e5 + 1);
    vector<bool> visited(1e5 + 1, false);
    pq.push({0, source});
    dist[source] = 0;

    while (!pq.empty())
    {
        uint64 vtx = pq.top().second;
        pq.pop();
        if (visited[vtx]) continue;
        visited[vtx] = 1;
        for (auto x : adj[vtx])
        {
            uint64 v = x.first;
            uint64 weight = x.second;

            if (dist[vtx] + weight < dist[v])
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
    vector<int> path;
    path.pb(vertex);
    int index = vertex;
    while (true)
    {
        index = sources[index];
        path.pb(index);
        if (index == 1) break;
    }
    for (int k = path.size() - 1; k >= 0; k--)
    {
        cout << path[k] << " ";
    }
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> vertex >> edge;
    for (int k = 0; k < edge; k++)
    {
        int v1, v2, w;
        cin >> v1 >> v2 >> w;
        adj[v1].pb(make_pair(v2, w));
        adj[v2].pb(make_pair(v1, w));
    }
    dijkstra();

    return 0;
}