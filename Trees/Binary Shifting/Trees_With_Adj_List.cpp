#include <bits/stdc++.h>
using namespace std;

/*
Binary Shifting means jumping in the power of 2

instead of node->parent->parent->parent->.....(till kth ancestor) which takes O(k) time
we can use binary lifting to find the kth ancestor in O(log k) time
For this we compute the 2^j parent of each node
*/

/*
any number k , say k=13= 1101₂ = 8 + 4 + 1
so we can find the 13th ancestor by jumping 8, 4, and 1 steps
*/

// up[node][j]->2^j th ancestor of node
// up[node][j] = up[up[node][j-1]][j-1]
// 2^j ancestor= 2^(j-1) ancestor of (2^(j-1)th ancestor)

class BinaryLifting{
    public:
    int LOG;
    vector<vector<int>> adj;
    vector<vector<int>> up;
    vector<int> depth; // depth of each node-> distance from the root node

    BinaryLifting(int n){
        LOG=ceil(log2(n))+1; // this increases the computation , even LOG=20 is enough
        adj.assign(n,vector<int>());
        up.assign(n,vector<int>(LOG,-1));
        depth.assign(n,0);
    }

    void addEdge(int u , int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // to compute the depth and up array-> dfs
    void dfs(int node , int parent){
        up[node][0]=parent;

        for(int j=1;j<LOG;j++){
            if(up[node][j-1]!=-1){
                up[node][j]=up[up[node][j-1]][j-1];
            }
        }

        for(auto &child : adj[node]){
            if(child==parent) continue;
            depth[child]=depth[node]+1;
            dfs(child,node);
        }
    }

    void build(int root){
        // remember depth of root == 0
        dfs(root,-1);
    }

    int getKthAncestor(int node, int k){
        //lifting the node k steps up
        for(int i=0;i<LOG;i++){
            if(k&(1<<i)){ // if the i-th bit is set , lift it by 2^i steps
                node=up[node][i];
                if(node==-1) return -1;
            }
        }
        return node;
    }

    int LCA(int u, int v){
        
        //make both the nodes at equal level , will lift the deeper node up
        if(depth[u]<depth[v]) swap(u,v);
        u=getKthAncestor(u,depth[u]-depth[v]);
        
        // if both the nodes are same , then that is the LCA
        if(u==v) return u;
        
        // now lift both the nodes up until they are not equal
        for(int j=LOG-1;j>=0;j--){
            if(up[u][j]!=-1 && up[u][j]!=up[v][j]){
                u=up[u][j];
                v=up[v][j];
            }
        }
        
        // we are just below the LCA->return its parent == LCA
        return up[u][0];
    }
};
