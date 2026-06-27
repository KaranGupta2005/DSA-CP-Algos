#include <bits/stdc++.h>
using namespace std;

/*
Fenwick Tree
- Subtree Sum Queries , Subtree Update Queries , XOR Queries : Then Fenwick Tree is more helpful
- Here , we store the node values inside the flatten array ( not the euler order ) : Flatten Valued Array
- Range Sum + Point Update : best data structure is Fenwick Tree
- Flow : Original Tree -> Euler Tour -> Flattened Array -> Fenwick Tree -> Answer Queries ( O(logN) )

- Fenwick tree can work with only associative operations , and in Sum operations and Xor Queries becasue prefix queries and xor queries can be inverted
- a^a = 0 , so we can remove the prefix from the range
- Similiary , a-a = 0 , so we can remove the prefix from the range
*/

// Euler's Tour

const int MAXN=200005;

vector<int> adj[MAXN];

int tin[MAXN] , tout[MAXN] , value[MAXN] , flat[MAXN];
int timer=0;

void dfs(int node , int parent){
    tin[node]=timer;
    flat[timer]=value[node];
    timer++;

    for(int child:adj[node]){
        if(child!=parent){
            dfs(child,node);
        }
    }
    
    tout[node]=timer-1;
}

// Fenwick Tree
struct fenwick{
    int n;
    vector<long long> bit;
    
    fenwick(int size){
        n=size;
        bit.assign(n+1,0);
    }

    void update(int idx , int delta){
        idx++;

        while(idx<=n){
            bit[idx]+=delta;
            idx+=(idx&(-idx));
        }
    }

    long long query(int idx){
        idx++;

        long long sum=0;
        while(idx>=0){
            sum+=bit[idx];
            idx-=(idx&(-idx));
        }
        return sum;
    }

    long long rangeQuery(int l , int r){
        return query(r) - query(l-1);
    }
};

// Main Function
int main(){

    // building a fenwick tree
    fenwick ft(20);
    for(int i=0;i<20;i++){
        ft.update(i,flat[i]);
    }

    // subtree sum -> say for node 2
    cout << ft.rangeQuery(tin[2], tout[2]) << endl;

    // path sum -> say for path from node 1 to node 3
    cout << ft.rangeQuery(tin[1], tout[3]) << endl;

    // update query -> say for node 2 from original 1 to 10 : diff=9
    ft.update(tin[2], 9);

    return 0;
}
