#include <bits/stdc++.h>
using namespace std;

/*
lower bound -> first element >=x
upper bound -> first element >x

Hence, case of first true;
*/

int lowerBound(vector<int>& arr , int target){
    int low=0;
    int high=arr.size()-1;

    int ans=-1;

    while(low<=high){
        int mid=low+(high-low)/2;

        if(arr[mid]>=target){
            ans=mid;
            high=mid-1; // first true
        }else{
            low=mid+1;
        }
    }
    
    return ans;
}