#include <bits/stdc++.h>
using namespace std;

/*
Union by Rank
- Here we store the estimated heights of the nodes
- We always merge the smaller tree to a larger tree , not the reverse
- When the rank of two nodes is same , the rank of the parent increases by 1
*/

class DSU{
public:

    vector<int> parent , rank;

    DSU(int n){
        parent.resize(n);
        rank.assign(n , 0);

        for(int i=0 ; i<n ; i++){
            parent[i]=i;
        }
    }

    int find(int x){
        if(x==parent[x]) return x;

        return parent[x]=find(parent[x]);
    }

    bool unite(int u , int v){
        u=find(u);
        v=find(v);

        if(u==v) return false; // both belong to the same component

        if(rank[u]<rank[v]) swap(u,v);

        parent[v]=u;

        if(rank[u]==rank[v]) rank[u]++;

        return true;
    }
};

