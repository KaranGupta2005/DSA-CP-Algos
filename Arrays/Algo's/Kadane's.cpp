#include <bits/stdc++.h>
using namespace std;

/*
Kadane's Algorithm

Maximum & Minimum Subarray Sum
- at each index i think whether:
    - extend the previous subarray
    - or start a new one

- DP interpretation
- dp[i]=maximum subarray sum ending at index i
    - dp[i]=max(arr[i],dp[i-1]+arr[i])
*/

int kadane(vector<int>& arr){
    int curr=arr[0];
    int maxi=arr[0];

    for(int i=1;i<arr.size();i++){
        curr=max(arr[i],curr+arr[i]); 
        maxi=max(maxi,curr);
    }

    return maxi;
}

// in minimum subarray sum -> use min
int minKadane(vector<int>& nums){

    int curr=nums[0];
    int best=nums[0];

    for(int i=1;i<nums.size();i++){

        curr=min(nums[i],
                 curr+nums[i]);

        best=min(best,curr);
    }

    return best;
}

/*
Maximum Circular Subarray Sum
- Intuition: pick everything except for the worst subarray
- 3 cases:
  - max subarray sum (non-circular)
  - total sum - min subarray sum (circular)
  - if all the elements are negative:
    - total sum - min subarray sum == 0 (invalid)
    - return max subarray sum

Minimum Circular Subarray Sum
- similar logic
- 3 cases:
  - min subarray sum (non-circular)
  - total sum - max subarray sum (circular)
  - if all the elements are positive:
    - total sum - max subarray sum == 0 (invalid)
    - return min subarray sum
*/

int maximumCircularSubarraySum(vector<int>& arr){
    
    int maxSum=arr[0];
    int currMax=arr[0];

    int minSum=arr[0];
    int currMin=arr[0];

    int total=arr[0];

    for(int i=1;i<arr.size();i++){
        currMax=max(arr[i],currMax+arr[i]);
        maxSum=max(maxSum,currMax);
        
        currMin=min(arr[i],currMin+arr[i]);
        minSum=min(minSum,currMin);

        total+=arr[i];
    }
    
    if(maxSum<0) return maxSum;

    return max(maxSum,total-minSum);
}
