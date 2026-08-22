#include <bits/stdc++.h>
using namespace std;

/* 
DSU (Disjoint Set Union / Union Set)
- This is a special graph data structure that is used to :
    - Detects cycle in undirected graphs : detects whether adding an edge creates a cycle or not
    - Kruskal's MST : Check if two vertices are already connected before adding an edge 
    - To track connected components and merge them efficiently
    - Network Connectivity Problem ( which involves grouping and merging )
    - Finds an extra edge creating a cycle
- Find(x) : returns the representative ( parent / root ) containing node x
- Union(x,y) : merge sets containing x , y

Without Optimization : 
Find : O(N)
Union : O(N)

With Optimization :
(path compression + union by rank / size)
Find : O(alpha(N))
Union : O(alpha(N))
Where alpha(N) is the inverse Ackermann function, which grows extremely slowly and is effectively a small constant(5) for all practical values of N.
*/

class DSU{
    public:
    
    int components;
    vector<int> parent , size;

    DSU(int n){
        components=n; // for components size
        parent.resize(n);
        size.assign(n , 1);

        // initially everyone is connected to themselves only
        for(int i=0 ; i<n ; i++){
            parent[i]=i;
        }
    }

    int find(int x){
        if(parent[x]==x) return x;
        return parent[x]=find(parent[x]);
    }

    bool unite(int u , int v){
        u=find(u);
        v=find(v);

        if(u==v){
            return false;
        }

        if(size[u] < size[v]) swap(u,v);

        parent[v]=u; // small to large merging
        size[u]+=size[v];
        components--; // reduce component count
        return true;
    }

    int componentSize(int x){
        return size[find(x)];
    }
    
    int getComponents(){
        return components;
    }
}

