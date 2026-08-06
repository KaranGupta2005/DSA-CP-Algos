#include <bits/stdc++.h>
using namespace std;

/*
Frog Jump
- A frog can jump 1 or 2 steps forward , and the energy utilised is the absolute diff b/w the heights of source and destination step
- Given an array of heights, find the minimum energy required to reach the last step

- State : dp[i] : minimum energy required to reach the ith step
- Since the frog can reach the ith step either from (i-2)th or the (i-1)th step
- Transition :
        -Jump1: dp[i-1] + |heights[i] - heights[i-1]|
        -Jump2: dp[i-2] + |heights[i] - heights[i-2]|
        -dp[i]: min(Jump1, Jump2)
- Base Case: dp[0] = 0
- Answer: dp[n-1]
*/

// Memoization
vector<int> dp;

int solve(int i , vector<int>& h){

    if(i==0) return 0;

    if(dp[i]!=-1) return dp[i];

    int jump1=solve(i-1 , h) + abs(h[i] - h[i-1]);

    int jump2=INT_MAX;
    if(i>1) jump2=solve(i-2 , h) + abs(h[i] - h[i-2]);
    
    return dp[i] = min(jump1, jump2);
}

// Tabulation
int frogJump(vector<int>& h){

    // we are moving in forward direction
    int n=h.size();

    vector<int> dp(n,0);
    dp[0]=0;

    for(int i=1 ; i<n ; i++){
        int jump1=dp[i-1] + abs(h[i] - h[i-1]);
        int jump2=INT_MAX;
        if(i>1) jump2=dp[i-2] + abs(h[i] - h[i-2]);
        dp[i]=min(jump1, jump2);
    }

    return dp[n-1];
}

// Space Optimisation
int frogJump(vector<int>& h){

    int n=h.size();

    int prev2=0 , prev1=0;

    for(int i=1 ; i<n ; i++){
        int jump1=prev1 + abs(h[i] - h[i-1]);
        int jump2=INT_MAX;
        if(i>1) jump2=prev2 + abs(h[i] - h[i-2]);
        int cur=min(jump1, jump2);
        prev2=prev1;
        prev1=cur;
    }

    return prev1;
}
