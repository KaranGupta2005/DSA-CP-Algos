#include <bits/stdc++.h>
using namespace std;

// same as Sum Queries , just replace += with ^=

// euler tour
int MAXN=200005;
vector<int> adj[MAXN];

int tin[MAXN], tout[MAXN] , value[MAXN] , flat[MAXN];
int timer=0;

void dfs(int node , int parent){

    tin[node] = timer;
    flat[timer] = value[node];
    timer++;

    for(int child : adj[node]) {
        if(child != parent) {
            dfs(child, node);
        }
    }

    tout[node] = timer-1;
}

// Fenwick Tree

struct fenwick{
    int n;
    vector<long long> bit;

    fenwick(int size){
        n=size;
        bit.assign(n+1,0);
    }

    void update(int idx , int val){
        idx++;

        while(idx<n){
            bit[idx] ^= val;
            idx += (idx & (-idx));
        }
    }

    int query(int idx){
        idx++;

        long long res = 0;
        while(idx>0){
            res ^= bit[idx];
            idx -= (idx & (-idx));
        }
        return res;
    }

    int rangeQuery(int l , int r){
        return query(r) ^ query(l-1);
    }
};
