#include <bits/stdc++.h>
using namespace std;

//to create unique permutations of an array with or without duplicates
//we are choosing all the possible choices for each index

void helper(vector<int>& nums, vector<vector<int>>& ans , int idx) {
    if(idx==nums.size()){
        ans.push_back(nums);
        return;
    }
    
    // maintaining a set to track which elements are already processed in a recursive call
    unordered_set<int> st;
    
    for(int i=idx;i<nums.size();i++){
        if(st.find(nums[i])!=st.end()) continue;
        st.insert(nums[i]);

        swap(nums[idx],nums[i]);
        helper(nums,ans,idx+1);
        swap(nums[idx],nums[i]);
    }
}

int main(){
    vector<int> nums;
    int len;
    cin>>len;
    nums.resize(len);
    for(int i=0;i<len;i++){
        cin>>nums[i];
    }
    vector<vector<int>> ans;
    helper(nums,ans,0);
    for(auto i:ans){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}