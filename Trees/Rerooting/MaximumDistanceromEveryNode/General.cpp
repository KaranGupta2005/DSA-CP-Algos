#include <bits/stdc++.h>
using namespace std;

/*
Maximum Distance from Every Node
- For every node , we need to find the farthest node from it -> rerooting
- down[node] : longest distance inside the subtree : dfs1
- up[node] : longest distance outside the subtree  : dfs2
- for maximum distance - no need for prefix or suffix in dfs2 -> only keep track of the best and the secondBest sibling 

- answer[node] = max(down[node], up[node])
*/

const int MAXN=100005;
int down[MAXN];
int up[MAXN];
vector<int> adj[MAXN];

void dfs1(int node , int parent){
    down[node]=0;

    for(auto &child:adj[node]){
        if(child==parent) continue;

        dfs1(child , node);

        down[node]=max(down[node] , down[child]+1); // +1 : coz node->child wali edge bhi consider krni hn
    }
}

void dfs2(int node , int parent){
    int mx1=-1 , mx2=-1;

    for(auto &child:adj[node]){
        if(child==parent) continue;

        int val=down[child];
        if(val>mx1){
            mx2=mx1;
            mx1=val;
        }
        else if(val>mx2){
            mx2=val;
        }
    }

    for(auto &child:adj[node]){
        if(child==parent) continue;
        
        int use=mx1;

        // if the best sibling is the current child, use the second best
        if(down[child]==mx1){
            use=mx2;
        }
        
        // child     parent             (node->child edge)
        up[child]=max(up[node], use+1) + 1;
        //             sibling(child for parent(node))

        dfs2(child , node);
    }
}

vector<int> solve(int n, vector<pair<int,int>>& edges){
    
    for(auto &edge:edges){
        int u=edge.first;
        int v=edge.second;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    dfs1(1, -1);
    dfs2(1, -1);

    vector<int> result;
    
    for(int i=1;i<=n;i++){
        result.push_back(max(down[i], up[i]));
    }
    
    return result;
}
