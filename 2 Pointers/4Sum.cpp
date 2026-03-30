#include <bits/stdc++.h>
using namespace std;

// we'll fix i,j and then use hashset to find the remaining two elements
// similar to 3sum
vector<vector<int>> hashing(vector<int>& nums, int target) {
    int n=nums.size();
    set<vector<int>> st;

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            unordered_set<int> hashset;
            for(int k=j+1;k<n;k++){
                long long need=(long long)target - nums[i] -nums[j] -nums[k];
                if(hashset.count(need)){
                    vector<int> temp={nums[i], nums[j], nums[k], (int)need};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
                hashset.insert(nums[k]);
            }
        }
    }
    
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}
// T.C -> O(N^3 * log(no. of unique quads))
// S.C -> O(2 * no. of unique quads) + O(N)

// sort the array intially
// fix i,j,k and then use binary search for the remaining element
vector<vector<int>> binarSearch(vector<int>& nums, int target) {
    int n=nums.size();
    vector<vector<int>> ans;

    sort(nums.begin(),nums.end());

    for(int i=0;i<n;i++){
        if(i>0 && nums[i]==nums[i-1]) continue;
        
        for(int j=i+1;j<n;j++){
            if(j>(i+1) && nums[j]==nums[j-1]) continue;

            for(int k=j+1;k<n;k++){
                if(k>(j+1) && nums[k]==nums[k-1]) continue;

                long long need=(long long)target - nums[i] - nums[j] - nums[k];

                //binary search for the remaining element
                int low=k+1 , high=n-1;
                while(low<=high){
                    int mid=low+(high-low)/2;

                    if(nums[mid]==need){
                        ans.push_back({nums[i], nums[j], nums[k], nums[mid]});
                        break;
                    }
                    else if(nums[mid]<need){
                        low=mid+1;
                    }
                    else{
                        high=mid-1;
                    }
                }
            }
        }
    }
    return ans;
}
// T.C -> O(N^3 * log(N))
// S.C -> O(1)

vector<vector<int>> twoPointers(vector<int>& nums, int target) {
    int n=nums.size();
    vector<vector<int>> ans;

    sort(nums.begin(), nums.end());

    for(int i=0;i<n;i++){
        if(i>0 && nums[i]==nums[i-1]) continue;

        //pruning
        if((i+3)<n && nums[i]+nums[i+1]+nums[i+2]+nums[i+3]>target) break;
        if((i+3)<n && nums[i]+nums[n-3]+nums[n-2]+nums[n-1]<target) continue;

        for(int j=i+1;j<n;j++){
            if(j>(i+1) && nums[j]==nums[j-1]) continue;
            
            //pruning
            if((j+2)<n && nums[i]+nums[j]+nums[j+1]+nums[j+2]>target) break;
            if((j+2)<n && nums[i]+nums[j]+nums[n-2]+nums[n-1]<target) continue;

            int left=j+1 , right=n-1;

            while(left<right){
                long long sum=(long long)nums[i]+nums[j]+nums[left]+nums[right];
                if(sum==target){
                    ans.push_back({nums[i], nums[j], nums[left], nums[right]});
                
                    while(left<right && nums[left]==nums[left-1]) left++;
                    while(left<right && nums[right]==nums[right+1]) right--;

                    left++;
                    right--;
                }
                else if(sum<target){
                    left++;
                }
                else{
                    right--;
                }
            }
            
        }
    }
    return ans;
}