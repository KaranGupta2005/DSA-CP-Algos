#include <bits/stdc++.h>
using namespace std;

/*
Search in Rotated Sorted Array
- nums = [4,5,6,7,0,1,2]
- rotation only creates one break , so [mid,r] or [l,mid] should be sorted
- always try to search in sorted half first
- if(nums[l]<=nums[mid]) -> left half is sorted , otherwise right part is sorted
*/

int search(vector<int>& nums, int target) {
    int n=nums.size();
    int low=0 , high=n-1;

    while(low<=high){
        int mid=low+(high-low)/2;

        if(nums[mid]==target) return mid;

        if(nums[mid] >= nums[low]){
            // left half is sorted
            if(target>=nums[low] && target<nums[mid]){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }else{
            // right half is sorted 
            if(target>nums[mid] && target<=nums[high]){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
    }
    return -1;
}

// Time Complexity: O(log n)
// Space Complexity: O(1)
