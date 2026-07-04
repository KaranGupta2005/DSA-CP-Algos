#include <bits/stdc++.h>
using namespace std;

/*
Heavy Light Decomposition:
- Operations / query on paths between nodes is not possible by Euler Tour
- In Euler tour , the subtrees are a continuous block , but not so for paths , they are scattered
- HLD breaks the tree into disjoint chains , and each chain can be represented as a contiguous subarray 

- Some branches in the tree are heavy ( longest child subtree ) and the remaining are light
                1
              /   \
             2     3
           / | \
          4  5  6
         /
        7
       /
      8

- Here , Largest child of 2 -> 4 ( size = 4 ) , so 4 is heavy child , 5 and 6 are light children
- Similiar for other nodes , 4 -> 7 ( size = 2 ) , 7 -> 8 ( size = 1 )
- So , 1->2->4->7->8 is a heavy path 

- Suppose an edge is light , then childSubTree <= parentSubTree / 2 : heavy child subtree will have at least as many nodes as other child
- Therefore , any path cross only log2(n) light edges => the path can be broken into O(log2(n)) chains 
- Each Segment Tree query takes O(log2n) time => total time complexity is O(log2n * log2n)
*/

const int MAXN=200005;

vector<int> adj[MAXN];
int value[MAXN];

int parent[MAXN] , depth[MAXN];
int heavy[MAXN] , head[MAXN] , pos[MAXN] , subTree[MAXN];

int baseArray[MAXN]; // based on pos array ( not node values )
int tree[4*MAXN]; // for segment tree operations

// DFS-1: Computes parent , depth , subtree size , heavy array
int dfs(int node , int par){
    parent[node]=par;
    subTree[node]=1;
    int maxSubTree=0;
    heavy[node]=-1;
    
    for(int &child : adj[node]){

        if(child==par) continue;

        int childSize=dfs(child , node);

        depth[child]=depth[node]+1;
        if(childSize>maxSubTree){
            maxSubTree=childSize;
            heavy[node]=child;
        }

        subTree[node]+=childSize;

    }
    return subTree[node];
}

int currPos=0;
/*
DFS-2: Heavy-Light Decomposition ( to compute the head ( head of the heavy chain ) and pos ( position in segment tree) arrays )
- First of all will cover the heavy child , bcoz they should exists at contiguous position in chain
- chainHead of heavy child will be same as current node ( belong to the same chain )

- Then move onto light children
- chainHead of light child will be the light child itself ( new chain started here )

*/
void decompose(int node , int chainHead){
    head[node]=chainHead;
    pos[node]=currPos;
    baseArray[currPos]=value[node];
    currPos++;

    if(heavy[node]!=-1){
        decompose(heavy[node],chainHead);
    }

    for(int child : adj[node]){
        if(child!=parent[node] && child!=heavy[node]){
            decompose(child,child);
        }
    }
}

//Segment Tree
void build(int node , int l , int r){
    if(l==r){
        tree[node]=baseArray[l];
        retrun;
    }

    int mid=(l+r)/2;

    build(2*node,l,mid);
    build(2*node+1,mid+1,r);

    tree[node]=tree[2*node]+tree[2*node+1];
}

void update(int node , int l , int r , int idx , int val){
    if(l==r){
        tree[node]=val;
        return;
    }

    int mid=(l+r)/2;

    if(idx<=mid){
        update(2*node , l , mid , idx , val);
    }else{
        update(2*node+1 , mid+1 , r , idx , val);
    }
    
    tree[node]=tree[2*node]+tree[2*node+1];
}

long long query(int node , int l , int r , int x , int y){
    if(l>y || r<x) return 0;
    if(l>=x && r<=y) return tree[node];
    
    int mid=(l+r)/2;
    return query(2*node , l , mid , x , y) + query(2*node+1 , mid+1 , r , x , y);
}

// HLD Query
// Here n is the total number of nodes in the tree
// Until the head of chains of u and v are not same , they belong to different chains , lift them up chain by chain
long long queryPath(int u , int v , int n){

    long long res=0;
    while(head[u]!=head[v]){
        if(depth[head[u]]<depth[head[v]]){
            swap(u,v);
        }
        // query from head[u] to u
        res+=query(1,0,n-1,pos[head[u]],pos[u]);
        u=parent[head[u]];
    }

    if(depth[u]<depth[v]) swap(u,v);
    // query from v to u (including lca)
    res+=query(1,0,n-1,pos[v],pos[u]);
    return res;
}

void updateNode(int node , int val , int n){
    value[node]=val;
    update(1,0,n-1,pos[node],val);
}

/*
Changing the Segment Tree:

-> Maximum
tree[node] = max(tree[2*node], tree[2*node+1]);
return max(leftAns , rightAns)
Identity : INT_MIN

-> Minimum
tree[node] = min(tree[2*node], tree[2*node+1]);
return min(leftAns , rightAns)
Identity : INT_MAX

-> XOR
tree[node] = tree[2*node] ^ tree[2*node+1];
return leftAns ^ rightAns
Identity : 0

-> GCD
tree[node] = __gcd(tree[2*node], tree[2*node+1]);
return __gcd(leftAns , rightAns)
Identity : 0

*/