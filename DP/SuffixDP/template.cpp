#include <bits/stdc++.h>
using namespace std;

/*
SUFFIX DP
- when we are building answer from index i to end
- dp[i][k] : best answer using elements from index i to n-1 with k parts

- dp[i][k]: min over j(i->n-1):
           cost(i->j) + dp[j+1][k-1]
// [i.....j] : first segment
// dp[j+1][k-1] : remaining segments

// CORE INTUITION : Where does the first segment ends
// fixed start and varying end
*/

long long solve(int i, int k, vector<vector<long long>>& dp){
    // base case
    if(i == n && k == 0) return 0;
    if(i == n || k == 0) return 1e18;
    
    if(k > n - i) return 1e18;

    if(dp[i][k] != -1) return dp[i][k];

    long long ans = 1e18;

    // try all possible cuts
    for(int j = i; j <= n-k; j++){
        long long next=solve(j + 1, k - 1, dp);
        if(next != 1e18)
            ans = min(ans, cost(i, j) + next);
    }

    return dp[i][k] = ans;
}

/*_____TABULATION_____

dp[i][k] depends upon dp[j+1][k-1]

// we will be moving i-> backward (n to 0)
// we will be moving k-> forward (1 to k)

*/

long long solveTabulation(){
    vector<vector<long long>> dp(n + 1, vector<long long>(k + 1, 1e18));
    
    // base case
    dp[n][0] = 0;
    
    // fill the dp table
    for(int i = n - 1; i >= 0; i--){
        for(int j = 1; j <= min(k, n - i); j++){
            dp[i][j] = 1e18;
            for(int x = i; x <= n - j; x++){
                long long next = dp[x + 1][j - 1];
                if(next != 1e18)
                    dp[i][j] = min(dp[i][j], cost(i, x) + next);
            }
        }
    }
    
    return dp[0][k];
}