#include <bits/stdc++.h>
using namespace std;

/*
Coin Change
- We are given coins array containing coins of different denominations and a target amount
- We have to return the minimum number of coins required to make the target amount
- We can use each coin an infinite number of times

- DP array of size (amount+1)
- State : dp[i] : minimum number of coins required to make amount i
- Transition : We have multiple choices to try : each coin
             : Apply a for loop ( for (coin : coins))
             : dp[i] = min(dp[i] , 1 + dp[i - coin])
- Base Case : dp[0] = 0 ( no coins needed to be chosen )
            : if amount<0 : 1e9 ( impossible )
- We will be moving in forward direction
*/

// Memoization
vector<int> dp;
int solve(int amount , vector<int>& coins) {
    
    if(amount==0) return 0;

    if(amount < 0) return 1e9;

    if(dp[amount]!=-1) return dp[amount];

    int ans=1e9;
    for(auto &coin : coins){
        ans=min(ans , 1 + solve(amount - coin, coins));
    }
    
    return dp[amount] = ans;
}

int coinChange(vector<int>& coins, int amount) {
    dp.assign(amount + 1, -1);
    int ans = solve(amount, coins);
    return ans >= 1e9 ? -1 : ans;
}

// Tabulation
int coinChangeTab(vector<int>& coins , int amount){

    vector<int> dp(amount+1 , 1e9);
    dp[0]=0;

    for(int i=1 ; i<=amount ; i++){
        for(auto &coin : coins){
            if(i>=coin){
                dp[i] = min(dp[i] , 1 + dp[i - coin]);
            }
        }
    }
    
    return dp[amount] == 1e9 ? -1 : dp[amount];
}
