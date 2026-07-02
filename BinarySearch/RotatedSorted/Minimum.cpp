#include <bits/stdc++.h>
using namespace std;

/*
Minimum in Rotated Sorted Array
- This is the element where rotation occurred -> 
- compare with the rightmost
- if(nums[mid] > nums[right]) -> the min is in the right
- if(nums[mid] < nums[right]) -> the min is in the left or mid
- if duplicates are present then (nums[mid]==nums[right]) -> right--
*/

int findMin(vector<int>& nums) {
    int left = 0;
    int right = nums.size() - 1;
    
    while (left < right) {
        int mid = left + (right - left) / 2;
        
        if (nums[mid] > nums[right]) {
            left = mid + 1;
        } else if (nums[mid] < nums[right]) {
            right = mid;
        } else {
            right--;
        }
    }
    
    return nums[left];
}
