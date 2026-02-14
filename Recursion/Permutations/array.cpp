#include <bits/stdc++.h>
using namespace std;

//to create unique permutations of an array with or without duplicates
//we are choosing all the possible choices for each index

void helper(vector<int>& nums , vector<int>& temp , vector<vector<int>>& ans , vector<bool>& used){
    if(temp.size()==nums.size()){
        ans.push_back(temp);
        return;
    }

    for(int i=0;i<nums.size();i++){
        //if already used, skip
        if(used[i]) continue;

        // instead of using a set to avoid duplicates -> which would lead to extra space
        // we can sort the array first and then skip the duplicates
        // if the same valued element is not used previously, skip the current element
        if(i>0 && (nums[i]==nums[i-1]) && !used[i-1]) continue;

        // choose one element
        used[i]=true;
        temp.push_back(nums[i]);

        // explore
        helper(nums,temp,ans,used);

        // unchoose,once the task is done and backtrack
        temp.pop_back();
        used[i]=false;
    }
}

int main(){
    vector<int> nums;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        nums.push_back(x);
    }
    sort(nums.begin(),nums.end());
    vector<int> temp;
    vector<vector<int>> ans;
    vector<bool> used(nums.size(),false);
    helper(nums,temp,ans,used);
    for(auto i:ans){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}
