#include <bits/stdc++.h>
using namespace std;

/*
Number of Subsequences with Equal GCD
- We have to return the number of pairs of subsequences where the GCD of all elements in both is equal.
- Both subsequences would be disjoint ( no element common )

- For each element int the array , we can :
    - Include it in first subsequence
    - Include it in second subsequence
    - Don't include it in any subsequence
- We need to remember only the curent GCD of seq1 , seq2

- DP state: dp[g1][g2] = number of ways to form subsequences with GCD g1 and g2
- DP[0][0]=1 : 0 represents an empty subsequence 

- If current element is x , then for every state (g1 , g2):
    - ignore x : (g1,g2)
    - put x into seq1 : (g1==0)? x:gcd(g1,x) : (ng1 , g2)
    - put x into seq2 : (g2==0)? x:gcd(g2,x) : (g1 , ng2)

- At last count where g1 == g2 and g1 != 0 ( non empty subsequences )

- Complexity:
    - Suppose n=nums.length() && M: max_element
    - Possible values of gcd: M+1 (0 to M) , therefore DP has (M+1)^2 states
    - Time: O(n * M^2) // processed for each element and each state
    - Space: O(M^2)
*/

const int MOD=1e9+7;

// substraction based gcd calculation is slower 
int gcd(int a , int b){
    if(b == 0) return a;
    return gcd(b, a % b);
}

int subsequencePairCount(vector<int>& nums){

    int maxi=*max_element(nums.begin(), nums.end());
    
    vector<vector<long long>> dp(maxi+1 , vector<long long>(maxi+1 , 0));
    dp[0][0] = 1;

    for(int &x:nums){

        vector<vector<long long>> ndp=dp;

        for(int g1=0 ; g1<=maxi ; g1++){
            for(int g2=0 ; g2<=maxi ; g2++){
                long long ways=dp[g1][g2];
                if(!ways) continue; // no way to form this state
                
                // put x into seq1
                int ng1= (g1==0)? x : gcd(g1,x);
                ndp[ng1][g2] = (ndp[ng1][g2] + ways) % MOD;
                
                // put x into seq2
                int ng2= (g2==0)? x : gcd(g2,x);
                ndp[g1][ng2] = (ndp[g1][ng2] + ways) % MOD;
            }
        }
        
        dp = ndp;
    }

    long long ans=0;
    for(int i=1 ; i<=maxi ; i++){
        ans = (ans + dp[i][i]) % MOD;
    }
    
    return ans;
}

