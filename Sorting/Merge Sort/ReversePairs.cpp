#include <bits/stdc++.h>
using namespace std;

/*
Reverse Pairs
- A reverse pair is (i,j) where i<j and arr[i] > 2*arr[j]
- Bruteforce : Check all pairs (i,j) where i<j and arr[i] > 2*arr[j] : O(n^2)
- Optimized : Using Merge Sort : O(n log n)
- Not the same as count inversions -> we will count by two pointers
- Left and right half : sorted && left : [l , mid] , right : [mid+1 , r]
- Contribution : count+=(j-(mid+1)) : (curr)-(first) : Since the right half is sorted 
               : We therefore don't reset j , j only moves forward
               : After counting , normal counting 
*/
long long merge(vector<int>& nums , int l , int mid , int r){
    long long count =0;
    vector<int> temp;

    int j=mid+1;
    for(int i=l ; i<=mid ; i++){
        while(j<=r && nums[i] <= 2LL * nums[j]) j++;
        count += (j - (mid + 1));
    }

    int i=l;
    j=mid+1;

    while(i<=mid && j<=r){
        if(nums[i] <= nums[j]) {
            temp.push_back(nums[i]);
            i++;
        }
        else {
            temp.push_back(nums[j]);
            j++;
        }
    }
    
    while(i<=mid) {
        temp.push_back(nums[i]);
        i++;
    }
    
    while(j<=r) {
        temp.push_back(nums[j]);
        j++;
    }
    
    for(int k=l ; k<=r ; k++) {
        nums[k] = temp[k-l];
    }
    
}
long long mergeSort(vector<int>& nums , int l , int r){
    if(l>=r) return 0;

    int mid=l+(r-l)/2;  
    long long count=0;
    count += mergeSort(nums , l , mid);
    count += mergeSort(nums , mid+1 , r);
    count += merge(nums , l , mid , r);
    return count;
}
int reversePairs(vector<int>& nums) {
    return mergeSort(nums , 0 , nums.size()-1);
}