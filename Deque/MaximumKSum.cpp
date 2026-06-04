#include <bits/stdc++.h>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    int n=nums.size();

    vector<int> ans;
    deque<int> dq;
    
    for(int i=0;i<n;i++){

        // remove out of window elements
        while(!dq.empty() && dq.front() <= (i-k)){
            dq.pop_front();
        }
        
        // maintaing a decreasing deque
        while(!dq.empty() && nums[dq.back()] <= nums[i]){
            dq.pop_back();
        }

        dq.push_back(i);

        // first window covered first -> [0...(k-1)]
        // max el : dq.front()
        if(i >= (k-1)){
            ans.push_back(nums[dq.front()]);
        }
    }
    
    return ans;
}
