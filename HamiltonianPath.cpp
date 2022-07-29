#include <bits/stdc++.h>

using namespace std;

#define pb push_back

vector<int> graph[(int)1e5 + 1];

void printPath(vector<int> const &path)
{
    // Print the Hamiltonian Path from start to end
    for (int x : path)
    {
        cout << x << " ";
    }
    cout << "\n";
}

void hamiltonianPath(int node, int size, vector<bool> &visited, vector<int> &path)
{
    // If all the nodes are visited, then the Hamiltonian Path exists
    if (path.size() == size)
    {
        printPath(path);
        return;
    }

    // Check if every edge starting of vertex "node" leads to a solution or not
    for (auto x : graph[node])
    {
        // Process only unvisited nodes as the Hamiltonian Path
        if (!visited[x])
        {
            visited[x] = true;
            path.pb(x);

            // Check if adding node "x" to the path leads to solution or not
            hamiltonianPath(x, size, visited, path);

            // Backtrack
            visited[x] = false;
            path.pop_back();
        }
    }
}

void findHamiltonianPaths(int size)
{
    // Check if Hamiltonian Path exists starting from all nodes
    for (int node = 1; node <= size; node++)
    {
        vector<int> path;
        path.pb(node); // Add starting node to the path

        vector<bool> visited(size + 1);
        visited[node] = true; // Mark the starting node as visited

        hamiltonianPath(node, size, visited, path);
    }
}

int main()
{
    int node, edge;
    cin >> node >> edge;
    while (edge--)
    {
        int node1, node2;
        cin >> node1 >> node2;
        // The "node1" is directed to "node2"
        graph[node1].pb(node2); // Add "node2" in adj list of "node1" 
    }
    // Find all possible Hamiltonian Path
    findHamiltonianPaths(node); 

    return 0;
}
