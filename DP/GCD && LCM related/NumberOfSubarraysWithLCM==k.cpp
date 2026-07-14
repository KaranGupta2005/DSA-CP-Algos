#include <bits/stdc++.h>
using namespace std;

/*
Number of Subarrays With LCM Equal to K

- Always ensure that lcm always increases or remains same on including next element
- If lcm becomes greater than k, we can break
    : if ( lcm > k || k%lcm!=0 ) break;
*/

int lcm(int a, int b){
    return (a/__gcd(a,b))*b;
}

int subarrayLCM(vector<int>& nums, int k){
    
    int n=nums.size();
    long long ans=0;

    for(int i=0;i<n;i++){
        int currLCM=nums[i];

        for(int j=i ; j<n ; j++){
            
            if(k%nums[j]!=0) break;
            
            currLCM=lcm(currLCM, nums[j]);
            
            if(currLCM==k) ans++;
            if(currLCM>k) break;
        }
    }
    
    return ans;
}

/*
for N=10^5 -> DP

- maintain dp[g] = number of subarrays ending at current position with LCM = g
- for each new element, update dp by merging with previous dp values
- only keep states where lcm divides k
*/

int subarrayLcmDP(vector<int>& nums, int k) {

    unordered_map<int, long long> dp;
    long long ans = 0;

    for (int x : nums) {

        if (k % x != 0) {
            dp.clear();
            continue;
        }

        unordered_map<int, long long> ndp;

        // start new subarray
        ndp[x]++;

        // extend previous ones
        for (auto &[l, cnt] : dp) {
            int nl = lcm(l, x);

            if (nl <= k && k % nl == 0)
                ndp[nl] += cnt;
        }

        ans += ndp[k];

        dp = move(ndp);
    }

    return ans;
}
