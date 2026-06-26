#include <bits/stdc++.h>
using namespace std;

/*
Count Smaller Numbers After Self
- In inversion and reverse pairs, we return only a single value
- But here we want the count of smaller numbers after each element
- hence we store { value , index } 
- and for each element we have to find the rightcounts ( elements smaller in the right that crossed it ) 
*/

void merge(vector<pair<int,int>>& res, int l, int mid, int r, vector<int>& ans){

    vector<pair<int,int>> temp;

    int i=l, j=mid+1;
    int rightCount=0;

    while(i<=mid && j<=r){

        if(res[i].first > res[j].first){
            rightCount++;
            temp.push_back(res[j++]);
        }
        else{
            ans[res[i].second] += rightCount;
            temp.push_back(res[i++]);
        }
    }

    while(i<=mid){
        ans[res[i].second] += rightCount;
        temp.push_back(res[i++]);
    }

    while(j<=r){
        temp.push_back(res[j++]);
    }

    for(int k=l;k<=r;k++)
        res[k]=temp[k-l];
}

void mergeSort(vector<pair<int,int>>& res , int l , int r , vector<int>& ans){
    if(l>=r) return ;

    int mid=l+(r-l)/2;

    mergeSort(res , l , mid , ans);
    mergeSort(res , mid+1 , r , ans);

    merge(res , l , mid , r , ans);
}
vector<int> countSmaller(vector<int>& nums){
    int n=nums.size();
    vector<pair<int,int>> res;

    for(int i=0;i<n;i++){
        res.push_back({nums[i],i});
    }

    vector<int> ans(n,0);
    mergeSort(res , 0 , n-1 , ans);

    return ans;
}