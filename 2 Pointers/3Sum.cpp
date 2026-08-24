#include <bits/stdc++.h>
using namespace std;

// in 3sum we find all the triplets {a,b,c} such that a+b+c==target
// the most naive approach is to use 3 nested loops -> o(n^3) time complexity
// and using set to avoid duplicates -> insertion overhead of o(log n)

/*
A better approach is to use hashing
- fix i , then solve nums[j]+nums[k] = -nums[i] -> converted to 2 sum
- use hashset to store elements and check if (-nums[i] - nums[j]) exists
- Problem is set insertion and we need to sort each triplet
*/
vector<vector<int>> hashing(vector<int>& nums) {
    int n=nums.size();
    set<vector<int>> st;

    for(int i=0;i<n;i++){
        unordered_set<int> hashset;

        for(int j=i+1;j<n;j++){
            int el=-(nums[i]+nums[j]);

            if(hashset.count(el)){
                vector<int> temp={nums[i],nums[j],el};
                sort(temp.begin(),temp.end());
                st.insert(temp);
            }
            hashset.insert(nums[j]);
        }
    }

    vector<vector<int>> res(st.begin(),st.end());
    return res;
}
/*
Time Complexity: O(N^2 * log M) where M is the number of unique triplets
Space Complexity: O(M) for the set + O(N) for the hashset
*/

/*
Finding the triplets using Binar Search

- fix i , j and find k such that nums[i] + nums[j] + nums[k] = 0
- use binary search to find k
- sort the array initially + avoid duplicates -> no need of set
*/
vector<vector<int>> binarySearch(vector<int>& nums) {
    int n=nums.size();
    vector<vector<int>> res;

    sort(nums.begin(),nums.end());

    for(int i=0;i<n;i++){

        if(i>0 && nums[i]==nums[i-1]) continue;

        for(int j=i+1;j<n;j++){
            if(j>(i+1) && nums[j]==nums[j-1]) continue;

            //binary search for k
            int target=-(nums[i]+nums[j]);
            int left=j+1 , right=n-1;

            while(left<=right){
                int mid=left+(right-left)/2;
                if(nums[mid]==target){
                    res.push_back({nums[i],nums[j],nums[mid]});
                    break;
                }
                else if(nums[mid]<target){
                    left=mid+1;
                }
                else{
                    right=mid-1;
                }
            }
        }
    }
    
    return res;
}
// Time Complexity: O(N^2 * log N)
// Space Complexity: O(1) excluding the space used for the output

/*
Finding the triplets using Two Pointers
- fix i , then use two pointers to find j and k
- sort the array initially + avoid duplicates -> no need of set
- fix , sort , reduce to 2 pointers
*/
vector<vector<int>> twoPointers(vector<int>& nums){
    int n=nums.size();
    vector<vector<int>> res;

    sort(nums.begin(),nums.end());

    for(int i=0;i<n;i++){
        if(i>0 && nums[i]==nums[i-1]) continue;
        
        //pruning
        if(i+2 < n && nums[i] + nums[i+1] + nums[i+2] > 0) break;
        
        if(i+2 < n && nums[i] + nums[n-1] + nums[n-2] < 0) continue;

        // apply two pointers on the remaining sorted array
        int left=i+1 , right=n-1;

        while(left<right){
            int sum=nums[i]+nums[left]+nums[right];

            if(sum==0){
                vector<int> temp={nums[i],nums[left],nums[right]};
                res.push_back(temp);

                //skip duplicates
                while(left<right && nums[left]==nums[left+1]) left++;
                while(left<right && nums[right]==nums[right-1]) right--;

                left++;
                right--;
            }
            else if(sum<0){
                left++; // if the sum < target .... increase the sum by moving left pointer to the right
            }
            else{
                right--; // if the sum > target .... decrease the sum by moving right pointer to the left
            }
        }
    }
    return res;
}
// Time Complexity: O(N^2)
// Space Complexity: O(1) excluding the space used for the output
