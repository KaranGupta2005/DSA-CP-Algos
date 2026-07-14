#include <bits/stdc++.h>
using namespace std;

int gcd(int a , int b){
    if(b==0) return a;
    return gcd(b, a%b);
}

vector<int> countSubsequencesWithEqualGCDs(vector<int>& nums) {
    
    int maxi=*max_element(nums.begin(), nums.end());
    
    vector<int> dp(maxi+1 , 0);
    dp[0]=1; // empty subsequence

    for(auto &el : nums){

        vector<int> ndp=dp;

        for(int g=1;g<=maxi;g++){
            if(dp[g]>0){
                int ng=gcd(g, el);
                ndp[ng]+=dp[g];
            }
        }
        dp=ndp;
    }
    return dp;
}