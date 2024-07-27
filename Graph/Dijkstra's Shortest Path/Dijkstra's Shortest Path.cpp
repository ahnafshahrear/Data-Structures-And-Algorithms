#include <bits/stdc++.h>

using namespace std;

//... Function to perform Dijkstra's algorithm to find single source shortest path from source to destination
void dijkstra(int nodes, vector<vector<pair<int, int>>>& graph, int source, int destination) {
    //... Priority queue to store <distance, node> pairs, sorted by distance in non-decreasing order
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, source}); //... Start with the source node

    int inf = 1e5;
    vector<int> distances(nodes, inf); //... To store the minimum distance from the source to each node
    //... Initially distances from the source to other nodes are infinite
    vector<int> sources(nodes, -1); //... To store the predecessor of each node

    distances[source] = 0; //... Distance from source to itself is 0
    
    while (!pq.empty()) {
        int node = pq.top().second; //... Get the node with the smallest distance
        pq.pop();

        for (auto edge : graph[node]) {
            int neighbour = edge.first, weight = edge.second;

            //... Path Relaxation: 
            //... If the path through the current node offers a shorter path to the neighbour, update it
            if (distances[node] + weight < distances[neighbour]) { 
                distances[neighbour] = distances[node] + weight;
                pq.push({distances[neighbour], neighbour});
                sources[neighbour] = node; //... Update the predecessor of the neighbor
                //... We are not breaking the loop when (neighbour == destination)
                //... That means we are computing the minimum cost from the source to other nodes
            }
        }
    }
    if (distances[destination] == inf) { //... There is no path exists from source to destination
        cout << "There is no path from source to destination!";
        return;
    }
    vector<int> path; //... To store the path from destination to source
    int parent = destination;

    while (parent != -1) { //... The source of the parent is -1
        path.push_back(parent);
        parent = sources[parent];
    }
    cout << "Minimum cost from source to destination is " << distances[destination]
         << "\n& The path from source to destination is: ";

    for (int i = path.size() - 1; i >= 0; i--) {
        cout << path[i] << " ";
    }
}
//... Time Complexity is O[V*log(V) + E] where V is the number of nodes & E is the number of edges

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int nodes, edges;
    cin >> nodes >> edges; //... Input the number of nodes & edges

    vector<vector<pair<int, int>>> graph(nodes); //... Adjacency list representation of the graph

    for (int k = 0; k < edges; k++) {
        int node1, node2, weight;
        cin >> node1 >> node2 >> weight; //... Input the edges with weights
        graph[node1].push_back({node2, weight});
        graph[node2].push_back({node1, weight});
    }
    int source, destination;
    cin >> source >> destination; //... Input the source node & the destination node

    dijkstra(nodes, graph, source, destination);

    return 0;
}

//... Ahnaf Shahrear Khan, Computer Science & Engineering, University of Rajshahi
//... Gmail: ahnafshahrearkhan@gmail.com
//... GitHub: https://github.com/ahnafshahrear
