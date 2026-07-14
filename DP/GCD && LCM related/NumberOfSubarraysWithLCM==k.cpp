#include <bits/stdc++.h>
using namespace std;

/*
Number of Subarrays With LCM Equal to K

- Always ensure that lcm always increases or remains same on including next element
- If lcm becomes greater than k, we can break
    : if ( lcm > k || k%lcm!=0 ) break;
*/
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