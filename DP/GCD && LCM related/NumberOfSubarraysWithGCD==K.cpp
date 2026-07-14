#include <bits/stdc++.h>
using namespace std;

/*
Number of subarrays with GCD == K

- Just ensure one thing GCD always decreases or remains same on including further elements
- While LCM always increases or remains same on including further elements

- if an element is not divisble by K , it can never be a part of any subarray with GCD == K
*/

int subarrayGCD(vector<int>& nums , int k){
    int n=nums.size();
    long long ans=0;

    for(int i=0 ; i<n ; i++){
        int g=0;

        for(int j=i ; j<n ; j++){

            if(nums[j]%k!=0) break;

            g=__gcd(g, nums[j]);

            if(g==k) ans++;
            if(g<k) break; // always decreases 
        }
    }
    return ans;
}

/*
If n==10^5 or something : DP 
- dp[g] : number of subarrays ending at index i-1 whose gcd is g
- When processing each nums[i]:
    - start a new subarray : only nums[i]
    - extend previous subarrays : new GCD : gcd(previous gcd, nums[i])
- Merge the counts of same GCDs to avoid TLE

- Since possible gcd values are log(a) where a: maximum value
    : Total complexity = O(n * log(a))
*/

int subarrayGcdDP(vector<int>& nums, int k){
    
    unordered_map<int , long long> dp;
    long long ans=0;

    for(auto &x : nums){

        unordered_map<int , long long> ndp;

        // start new subarray
        ndp[x]++;

        // extend previous subarrays 
        for(auto &[g,count]:dp){
            int ng=gcd(g,x);
            ndp[ng]+=count;
        }

        if(ndp.count(k)){
            ans+=ndp[k];
        }
        
        dp=ndp;
    }
    
    return ans;
}