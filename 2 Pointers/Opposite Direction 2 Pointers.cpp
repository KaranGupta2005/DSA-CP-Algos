#include <bits/stdc++.h>
using namespace std;

/*
Opposite Direction 2 Pointers:
- Applied when array is sorted and used when we need to compare elements from both ends
- Recognition: required pair/triplet ; target sum ; closest sum ; palindrome 
*/

/*
Target Sum
- when array is sorted ; and l=0 , r=n-1
    - a[l] + a[r] == target : found
    - a[l] + a[r] < target : l++ ( too small , need to increase )
    - a[l] + a[r] > target : r-- ( too large , need to decrease )
*/
vector<int> twoSum(vector<int>& nums, int target) {
    int l = 0, r = nums.size() - 1;
    sort(nums.begin(), nums.end());

    while (l < r) {
        long long sum = nums[l] + nums[r];
        if (sum == target) return {l, r};
        else if (sum < target) l++;
        else r--;
    }
    return {};
}
/*
- if array is not sorted , use hash maps
- for 3Sum or Generalized KSum
    : fix one element , then use 2Sum on remaining
    : time complexity O(n^2)
*/

/*
Closest Pair / Closest Sum
*/
vector<int> twoSumClosest(vector<int>& nums, int target) {
    int l = 0, r = nums.size() - 1;
    sort(nums.begin(), nums.end());
    
    int closest = INT_MAX;
    int ansL = -1, ansR = -1;
    
    while (l < r) {
        long long sum = nums[l] + nums[r];
        if (abs(sum - target) < closest) {
            closest = abs(sum - target);
            ansL = l;
            ansR = r;
        }
        if (sum < target) l++;
        else r--;
    }
    return {ansL, ansR};
}

/*
Container with Most Water
- the minimum boundary will decide the area containing water
- will always move to the smaller side 
- moving the larger side won't help increase the area : it will reduce the width and the limiting height cannot increase area
*/
int maxArea(vector<int>& height){
    int l=0 , r=height.size()-1;
    int maxArea = 0;

    while(l<r){
        long long h= min(height[l] , height[r]);
        long long w= r-l;
        maxArea= max(maxArea , h*w);

        if(height[l] < height[r]) l++;
        else r--;
    }
    return maxArea;
}


