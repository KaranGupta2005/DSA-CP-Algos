#include <bits/stdc++.h>
using namespace std;

/*
Jump Game VI
- exactly same as the problem constrained subsequense sum , where we need to find the maximum sum of a subsequence of length k
- here , just the constraint that the jumps can't go out of arr boundary

- dp[i] = maximum subsequece sum ending at index i
    : at index i we have two choices :
    - either start a new subsequence at idx i ( nums[i] )
    - or extend the subsequence from some previous index j ( max(dp[j]) + nums[i] )
    
    : so dp[i] = max(nums[i], max(dp[j]) + nums[i]) for all j in [i-k, i-1]

- we will be using a decreasing dq to find the max(dp[j]) for all j in [i-k, i-1] , since max element is always at the front
*/

class Solution {
public:
    int maxResult(vector<int>& nums, int k) {

        int n = nums.size();

        vector<int> dp(n);
        deque<int> dq;

        dp[0] = nums[0]; // base case
        dq.push_back(0); // so that we don't go out of bounds ( 0 is the first valid position )

        for (int i = 1; i < n; i++) {

            while (!dq.empty() && dq.front() < i - k)
                dq.pop_front();

            // Best score to reach i
            dp[i] = nums[i] + dp[dq.front()];

            while (!dq.empty() && dp[dq.back()] <= dp[i])
                dq.pop_back();

            dq.push_back(i);
        }

        return dp[n - 1];
    }
};