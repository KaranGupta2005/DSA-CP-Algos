#include <bits/stdc++.h>
using namespace std;

/*
PREFIX DP
- whenever in the problem it is given-> split the array , partition into k parts , optimize sum over subarrays , knapsack style problems
- you will be building the answer from first i elements
- dp[i][j] : dp state : best answer using FIRST i elements into j parts

- We are exploring all the cuts
Whole solution = (previous part) + (last segment)
dp[i][j] = min / max over p(0->i-1):
           dp[p][j-1] + cost(p+1->i)

// p-> last cuts
// [p+1 -> i] -> last segment
// dp[p][j-1] -> previous parts

// INTUITION : fix ending + varying starting

// cost DP has to be precomputed 
*/

long long solve(int i, int k, vector<vector<long long>>& dp){
    // base case
    if(i == 0 && k == 0) return 0;
    if(i == 0 || k == 0) return 1e18;
    
    if(k > i) return 1e18;

    if(dp[i][k] != -1) return dp[i][k];

    long long ans = 1e18;

    // trying all the previous cuts
    for(int p = 0; p < i; p++){
        long long prev = solve(p, k-1, dp);
        if(prev != 1e18){
            ans = min(ans, prev + cost(p+1, i));
        }
    }

    return dp[i][k] = ans;
}

/*-------Tabulation------------
Convert recursion to iteration

- base case: dp[0][0] = 0
- dp[i][k] depends on dp[p][k-1] for all p in [0, i-1]
- therefore will move k from 1 to k
*/ 

long long tabulation(int n, int k) {
    vector<vector<long long>> dp(n + 1, vector<long long>(k + 1, 1e18));
    dp[0][0] = 0;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= min(i, k); j++){
            for(int p = 0; p < i; p++){
                if(dp[p][j-1] != 1e18){
                    dp[i][j] = min(dp[i][j], dp[p][j-1] + cost(p+1, i));
                }
            }
        }
    }
    return dp[n][k]; 
}

// Time Complexity: O(n^2 * k)