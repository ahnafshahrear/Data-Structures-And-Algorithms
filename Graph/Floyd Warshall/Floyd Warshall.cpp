#include <bits/stdc++.h>

using namespace std;

//... This function updates the input graph to with the shortest distances between all pairs of nodes
void warshall(vector<vector<int>>& graph) {
    int nodes = graph.size();

    //... Make each k'th node as an intermediate node
    for (int k = 0; k < nodes; k++) {
        for (int i = 0; i < nodes; i++) {
            for (int j = 0; j < nodes; j++) {
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }
}
//... Time Complexity is O[n^3] where n is the number of nodes

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int nodes;
    cin >> nodes; //... Input the number of nodes

    vector<vector<int>> graph(nodes, vector<int> (nodes));

    //... Input the adjacency matrix, where graph[i][j] is the distance from i'th node to j'th node
    for (int i = 0; i < nodes; i++) {
        for (int j = 0; j < nodes; j++) {
            cin >> graph[i][j]; //... Input the weights
        }
    }
    warshall(graph);

    for (int i = 0; i < nodes; i++) {
        for (int j = 0; j < nodes; j++) {
            cout << graph[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}

//... Ahnaf Shahrear Khan, Computer Science & Engineering, University of Rajshahi
//... Gmail: ahnafshahrearkhan@gmail.com
//... GitHub: https://github.com/ahnafshahrear
