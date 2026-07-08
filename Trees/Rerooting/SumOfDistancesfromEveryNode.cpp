#include <bits/stdc++.h>
using namespace std;

/*
Rerooting DP:
- Used to solve a common class of problem : " Answer for every node , if all are considered as root"

Sum Of Distances from every node to the other
- Bruteforce : to apply DFS from every node : O(n^2)
- When the root changes , only the parent <-> children relation changes , the edges still remains the same
- For this problem whenever we move a node down 
    -> it's distance from the nodes in it's subtree decreases by 1 
    -> it's distance from the remaining nodes (outside subtree) increases by 1
- Suppose current root is 'u' -> ans[u]
    - we move to child v
    - N : total number of nodes , S : subtree[v] size
    - ans[v] = ans[u] - S + (N - S) = ans[u] - 2*S + N

- Every rerooting problem requires two dfs
- The first DFS collects information from children to parent : like subtree size , initial answer , depth sum , etc
- The second DFS propagates information from parent to children : here we can compute the child answer from parent aswer in O(1) instead of O(children)
*/

vector<vector<int>> adj;
vector<int> subtree;
vector<int> depth;
vector<int> ans;

void dfs1(int node , int parent){

    subtree[node]=1;
    ans[node]+=depth[node];

    for(int child : adj[node]){
        if(child == parent) continue;

        depth[child] = depth[node] + 1;
        dfs1(child, node);
        subtree[node] += subtree[child];
    }
}

void dfs2(int node , int parent , int n){
    for(int child : adj[node]){
        if(child == parent) continue;
        
        ans[child] = ans[node] - 2 * subtree[child] + n;
        dfs2(child, node, n);
    }
}

vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
    adj.assign(n,{});
    subtree.assign(n, 0);
    depth.assign(n, 0);
    ans.assign(n, 0);
    
    for(auto& edge : edges) {
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }
    
    dfs1(0, -1);
    dfs2(0, -1, n);
    
    return ans;
}
