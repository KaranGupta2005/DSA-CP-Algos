#include <bits/stdc++.h>
using namespace std;

/*
Star Graph
- It is a special type of tree / graph
- It has one center node and all other nodes (n-1) are connected to it
- It has n-1 edges
- Special property : every edge contains the center node , so first two edges should share a vertex
*/

int findCenter(vector<vector<int>>& edges) {
    
    if(edges[0][0]==edges[1][0] || edges[0][0]==edges[1][1]) {
        return edges[0][0];
    }
    return edges[0][1];
}