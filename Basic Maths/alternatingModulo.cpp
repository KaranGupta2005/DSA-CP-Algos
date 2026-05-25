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

int bfsHelper(int start , int end , int k, int step) {
    
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

int minOperations(vector<int>& nums , int k , int d) {
    int n=nums.size();
    int mini=INT_MAX;
    
    for(int x=0;x<k;x++){
        for(int y=0;y<k;y++){
            if(x==y) continue;
            
            int ops=0;
            bool possible=true;

            for(int i=0;i<n;i++){
                int val1=nums[i]%k;
                int val2=(i&1)?y:x;

                int add=bfsHelper(val1, val2, k, d);
                if(add==-1){
                    possible=false;
                    break;
                } 
                ops+=add;
                
            }
            if(possible) mini=min(mini, ops);
        }
    }
    
    return mini==INT_MAX?-1:mini;
}
// Time Complexity: O(k^3 * n)
// Space Complexity: O(k)

/*
Special Case when d=1: all the modular states are possible
- Which (x,y) where x,y belongs to [0,k-1] are reachable and x!=y : O(k^2)
- for min Operations:
    - forward: (target-curr+k)%k
    - backward: (curr-target+k)%k
    - +k: avoiding negative modulo
*/

int minOpeationsSpecial(vector<int>& nums , int k){

    int n=nums.size();
    int mini=INT_MAX;

    for(int x=0;x<k;x++){
        for(int y=0;y<k;y++){
            if(x==y) continue;

            int ops=0;

            for(int i=0;i<n;i++){
                int curr=nums[i]%k;
                int target=(i&1)?y:x;
                
                int forw=(target-curr+k)%k;
                int back=(curr-target+k)%k;
                
                ops+=min(forw,back);
            }
            
            mini=min(mini,ops);
        }
    }
    
    return mini==INT_MAX?-1:mini;
}

// Time Complexity: O(k^2 * n)
// Space Complexity: O(1)

