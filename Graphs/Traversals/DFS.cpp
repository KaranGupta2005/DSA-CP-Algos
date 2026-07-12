#include <bits/stdc++.h>
using namespace std;

/*
Graph DFS(Depth First Search)
- Go as deep as possible (until dead-end) and then return
- It uses a stack ( or a recursion stack )
- Need to maintain a visited array to ensure all nodes are visited once , otherwise infinite recursion 
- DFS traversal order is not unique , if you change the adjacency list order , you'll get a different traversal order
 
Intuition:
- for every node , mark it visited
- traverse all its adjacent unvisited neighbours

- Used to detect cycles , count components , whether a path exists or not , topological sort , etc.
- Time Complexity : O(V + E) where V is vertices and E is edges ( if adjacency list is used ) ( since all nodes traversed once )
- Space Complexity : O(V) for visited array and recursion stack
*/

void dfs(int node , vector<vector<int>>& adj , vector<bool>& visited){

    visited[node]=true;
    // processing
    cout<<node<<" ";

    // traverse all adjacent nodes
    for (int neighbour : adj[node]) {
        if (!visited[neighbour]) {
            dfs(neighbour, adj, visited);
        }
    }
}

int countComponents(int n, vector<vector<int>>& edges) {
    
    vector<vector<int>> adj(n);
    for (auto& edge : edges) {
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }
    
    vector<bool> visited(n, false);
    int count = 0;
    
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, adj, visited);
            count++;
        }
    }
    
    return count;
}