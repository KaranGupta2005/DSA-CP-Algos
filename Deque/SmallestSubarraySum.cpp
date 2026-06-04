#include <bits/stdc++.h>
using namespace std;

/*
Smallest Subarray with Sum >= target
- Normal Sliding window fails , because there we were sure that on removing elements from front, the sum will only decrease
- But here, we can have negative numbers, so removing elements from front might increase the sum

- we maintain prefix Sums in deque in increasing order
- whenever a suitable subarray if found (prefix[i]-dq.front() >= target), we update the result
- Then pop from front -> want smallest possible subarray
*/

int shortestSubarray(vector<int>& nums, int k) {
    int n=nums.size();
    
    vector<long long> prefixSums(n+1,0);
    for(int i=1;i<=n;i++){
        prefixSums[i]=prefixSums[i-1]+nums[i-1];
    }

    deque<int> dq;
    int ans=INT_MAX;

    for(int i=0;i<=n;i++){

        while(!dq.empty() && (prefixSums[i]-prefixSums[dq.front()]) >= k){
            ans = min(ans, i - dq.front());
            dq.pop_front();
        }

        while(!dq.empty() && prefixSums[dq.back()] >= prefixSums[i]){
            dq.pop_back();
        }
        
        dq.push_back(i);
    }
        
    return ans == INT_MAX ? -1 : ans;
}