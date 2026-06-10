#include <bits/stdc++.h>
using namespace std;

/*
Here the cost DP:
cost[l][r] = cost of substring from l to r
=> The number of elements that need to be changed to make it a palindrome
*/

int palindromePartition(string s, int k) {

        int n=s.length();
        
        vector<vector<int>> cost(n,vector<int>(n,0));
        // for len==1 ('a' to 'z') cost is 0
        // we are placing the costs lengthwise 
        for(int len=2;len<=n;len++){
            for(int l=0;l+len-1<n;l++){
                int r=l+len-1;

                if(len==2){
                    cost[l][r]=(s[l]!=s[r]);
                }else{
                    //         (last two characters) + (cost of inner substring)
                    cost[l][r]=   (s[l]!=s[r])       +   (cost[l+1][r-1]);
                }

            }
        }

        vector<vector<int>> dp(n+1,vector<int>(k+1,INT_MAX));

        dp[0][0]=0;

        for(int i=1;i<=n;i++){
            for(int j=1;j<=min(k,i);j++){
                for(int p=0;p<i;p++){
                    int prev=dp[p][j-1];

                    if(prev!=INT_MAX){
                        dp[i][j]=min(dp[i][j] , prev+cost[p][i-1]);
                    }
                }
            }
        }

        return dp[n][k];
    }