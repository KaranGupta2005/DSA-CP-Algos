#include <bits/stdc++.h>
using namespace std;

void mergeSortedArrays(vector<int>& arr1, vector<int>& arr2) {
    int n=arr1.size();
    int m=arr2.size();

    int left=n-1 , right=0;

    while(left>=0 && right<m){
        if(arr1[left] > arr2[right]){
            swap(arr1[left], arr2[right]);
            left--;
            right++;
        }
        else{
            break;
        }
    }
    
    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());

}

// this is merging the two sorted arrays in place 
// Time Complexity: O(min(n,m))+O(nlogn)+O(mlogm)
// Space Complexity: O(1)