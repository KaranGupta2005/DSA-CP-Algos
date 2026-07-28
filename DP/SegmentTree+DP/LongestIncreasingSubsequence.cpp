#include <bits/stdc++.h>
using namespace std;

/*
Longest Increasing Subsequence
- We are given an array nums and integer k , we need to find the length of LIS such that differnece b/w adjacent elements is <= k
- dp[i] : the maximum length of the LIS ending at index i
- Transition: dp[i] = max(dp[j] + 1) for all j < i where nums[i] - nums[j] <= k
- Base case: dp[i] = 1 for all i
*/

int lengthOfLIS(vector<int>& nums , int k){
    int n=nums.size();

    vector<int> dp(n, 1);

    int ans=0;
    
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<i ; j++){
            if(nums[i] > nums[j] && nums[i] - nums[j] <= k){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }

        ans = max(ans, dp[i]);
    }
    
    return ans;
}

/*
- Here see , for every i , we are checking all the previous elements j < i : O(n^2)
- We can optimize it using segment tree

- for each element nums[i] , we need the largest DP among the previous numbers : [nums[i]-k , nums[i]-1]
- We can use segment tree to query the maximum DP in the range [nums[i]-k , nums[i]-1] in O(log M) : where M is the maximum element
- instead of dp[i] , we store best[value] = maximum length of LIS ending with value
- initially , all the elemnets of best == 0 , then we will update based on the maximum in the range
*/
class Solution {
public:
    vector<int> tree;

    void update(int idx , int l , int r , int pos , int val){
        if(l==r){
            tree[idx]=max(tree[idx] , val); // since tree[idx] -> val , which may appear again in future
            return;
        }

        int mid=(l+r)/2;

        if(pos<=mid){
            update(2*idx , l , mid , pos , val);
        }else{
            update(2*idx+1 , mid+1 , r , pos , val);
        }

        tree[idx]=max(tree[2*idx] , tree[2*idx+1]);
    }

    int query(int idx , int l , int r , int ql , int qr){
        if(qr<l || r<ql) return 0;

        if(ql<=l && r<=qr){
            return tree[idx];
        }

        int mid=(l+r)/2;

        return max(query(2*idx , l , mid , ql , qr) , query(2*idx+1 , mid+1 , r , ql , qr));
    }
    int lengthOfLIS(vector<int>& nums, int k) {
        int maxi=*max_element(nums.begin() , nums.end());

        tree.assign(4*(maxi+1) , 0);

        int ans=1;

        for(auto &el : nums){
            int l=max(1 , el-k);
            int r=el-1;

            int best=0;
            if(l<=r){
                best=query(1 , 1 , maxi , l , r);
            }

            int curr=best+1;

            update(1 , 1 , maxi , el , curr);

            ans=max(ans , curr);
        }

        return ans;
    }
};
