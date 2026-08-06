#include <bits/stdc++.h>
using namespace std;

/*
Frog Jump K Distance
- Here instead of 1 or 2 steps , we can jump 1...K steps
- We need to find the minimum cost to reach the end
- Cost is the absolute difference between the heights

- Only the transition changes:
    - dp[i]=minimum of dp[i-j](for all i>=j and j<=k) + abs(h[i]-h[i-j])
- Whenever we can move up to K previous states and try out all the possible ways , then we use a loop in our transition
*/

// Memoization
vector<int>& dp;
int K;
int solve(int i , vector<int>& h){

    if(i == 0) return 0;

    if(dp[i]!=-1) return dp[i];

    int cost=INT_MAX;

    for(int j=1 ; j<=K ; j++){
        if(i-j >= 0){
            cost=min(cost , solve(i-j,h) + abs(h[i]-h[i-j]));
        }
    }

    return dp[i]=cost;
}

// Tabulation
int frogKJump(vector<int>& h, int n, int k){
    vector<int> dp(n, 0);
    
    for(int i=1 ; i<n ; i++){
        int cost=INT_MAX;
        for(int j=1 ; j<=k ; j++){
            if(i-j >= 0){
                cost=min(cost , dp[i-j] + abs(h[i]-h[i-j]));
            }
        }
        dp[i]=cost;
    }
    
    return dp[n-1];
}