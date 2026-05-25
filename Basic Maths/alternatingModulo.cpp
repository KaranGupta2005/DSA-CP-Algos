#include <bits/stdc++.h>
using namespace std;

/*
Alternating Modulo

- (num%k) belongs to [0,k-1)
- Here we need , (nums[i]%k) = x and (nums[i+1]%k) = y , both x and y belongs to [0,k-1)
- So we will loop i:0->k and second loop j:0->k : O(k^2) possibilities

- the modulo class is circular , i.e. we can reach a target by either forward or backward direction
0 → 1 → 2 → 3 → 4
↑                 ↓
└─────────────────┘
- if the step size is d , it breaks the modulo graph into gcd(d,k) components (if d=1, we can reach all nodes)
- so the most generalised way to make the curr(nums[i]%k) to target(x/y) is to find the shortest path by applying bfs on the modulo graph
- each modulo class-> node and each edges:
    - forward: u -> (u+d)%k
    - backward: u -> (u-d+k)%k

- we will do pruning for earlier exit by checking for gcd reachability
- we can reach: start->target iff:
    - (target-start) % gcd(d,k) == 0
*/

int gcd(int a , int b){
    return b == 0? a:gcd(b,a%b);
}

int minOperations(int start , int end , int k, int step) {
    
    start%=k;
    end%=k;

    int g=gcd(step,k);

    if((end-start)%g !=0) return -1; // not reachable

    //BFS
    vector<int>dist(k,-1);
    queue<int>q;

    dist[start]=0;
    q.push(start);

    while(!q.empty()){
        int curr=q.front();
        q.pop();

        if(curr==end) return dist[curr];
        
        int forw=(curr+step)%k;
        int back=(curr-step+k)%k;
        
        if(dist[forw]==-1){
            dist[forw]=dist[curr]+1;
            q.push(forw);
        }

        if(dist[back]==-1){
            dist[back]=dist[curr]+1;
            q.push(back);
        }
    }
    
    return -1; // not reachable
}
