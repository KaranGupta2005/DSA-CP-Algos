#include <bits/stdc++.h>
using namespace std;

/*
Maximum sum of non adjacent elements
- We need to find out the maximum sum of a subsequence such that no two elements are adjacent
- This is a classic House Robber Type dynamic programming problem

- At each element, we have two choices: 
    - include it: next allowed index: i+2
    - exclude it: next allowed index: i+1

- State: dp[i] : Maximum Sum starting from index i
- Transition : 
    - take = arr[i] + dp[i+2]
    - notTake = dp[i+1]
    - dp[i] = max(take, notTake)
- Base Case: 
    - if i >= n: return 0
- Here we are moving in backward direction
*/

// Memoization
vector<int> dp;

int solve(int i , vector<int>& arr){

    if(i>=arr.size()) return 0;

    if(dp[i] != -1) return dp[i];

    int take=arr[i]+solve(i+2 , arr);
    int skip=solve(i+1 , arr);

    return dp[i] = max(take, skip);
}

// Tabulation
int rob(vector<int>& arr){

    int n=arr.size();

    vector<int> dp(n+2,0);

    for(int i=n-1 ; i>=0 ; i--){
        int take = arr[i] + dp[i+2];
        int skip = dp[i+1];
        
        dp[i] = max(take, skip);
    }

    return dp[0];
}
