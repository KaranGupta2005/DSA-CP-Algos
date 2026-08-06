#include <bits/stdc++.h>
using namespace std;

/*
Maximum Balanced Subsequence Sum
- A balanced subsequence of length k follows : nums[ij] - nums[ij-1] >= ij - ij-1 for every j in [1 , k-1]
- dp[i]: maximum balanced subsequence sum ending at index i
- transition: dp[i] = max(dp[i] , dp[j] + nums[i]) for all j < i : O(n^2)
- base case : dp[i] = nums[i] : subsequence of length 1 is always balanced
*/

long long maxBalancedSubsequenceSum(vector<int>& nums) {
    int n=nums.size();

    vector<long long> dp(n , 0);

    long long ans=LLONG_MIN;

    for(int i=0 ; i<n ; i++){
        dp[i]=nums[i]; // base case

        for(int j=0 ; j<i ; j++){
            if(nums[i]-nums[j] >= i-j){
                dp[i]=max(dp[i] , dp[j]+nums[i]);
            }
        }

        ans=max(ans , dp[i]);
    }
    
    return ans;
}