#include <bits/stdc++.h>
using namespace std;

/*
Binary Search on Answer Space
- This is valid if we are finding the optimal value on a monotonic search space (declared , not given)
- We are not choosing the elements directly , but we are finding a threshold on a greedy condition check(mid) 

Type 1: spacing types problem
- maximize the minimum distance
- we have to find the last true : "maximize the minimum"
- Intuition:
    - Sort elements of the array and define range: low , high
    - Pick the earliest valid element : always leaves scope for the maximum distance b/w later elements
    - place elements until spacing >= d : count++ , and update the last placed element
*/

bool canPlace(vector<int>& arr , int k , int d){
    int last=arr[0];
    int count=1;

    for(int i=1;i<arr.size();i++){
        if((arr[i]-last)>=d){
            last=arr[i];
            count++;
        }
    }
    
    return count>=k;
}

int spacingType(vector<int>& arr , int k){
    int n=arr.size();
    sort(arr.begin(),arr.end());

    int low=0; // minimum spacing
    int high=arr[n-1]-arr[0]; // maximum spacing

    int ans=0;

    while(low<=high){
        int mid=low+(high-low)/2;

        if(canPlace(arr,k,mid)){
            // if it is possible to place >=k elements with minimum distance mid -> smaller will also satisfy , search greater
            ans=mid;
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }

    return ans;
}

// Time Complexity: O(n log n)
// Space Complexity: O(1)

