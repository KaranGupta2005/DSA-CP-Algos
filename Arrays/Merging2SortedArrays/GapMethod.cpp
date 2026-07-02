#include <bits/stdc++.h>
using namespace std;

// this method is also called as Shell Sort Method
// it is used to merge two sorted arrays in-place
// it sorts the array in O(len*log(len))
void mergeSortedArrays(vector<int>& arr1, vector<int>& arr2) {
    int n=arr1.size();
    int m=arr2.size();

    int len=n+m;
    int gap=(len/2)+(len%2); // alternative way to calculate ceil(len/2)

    auto swapGreater=[&](int idx1 , int idx2 , vector<int> &arr1 , vector<int> &arr2){
        if(arr1[idx1]>arr2[idx2]){
            swap(arr1[idx1],arr2[idx2]);
        }
    };

    // we will stop when gap becomes 1
    while(gap>=1){
        int left=0;
        int right=gap+left;

        while(right<len){
            if(left>=n && right<len){ // both the pointers are in arr2
                swapGreater(left-n,right-n,arr2,arr2);
            }
            else if(left<n && right>=n){ // left pointer is in arr1 and right pointer is in arr2
                swapGreater(left,right-n,arr1,arr2);
            }
            else{
                swapGreater(left,right,arr1,arr1); // both the pointers are in arr1
            }
            left++;
            right++;
        }

        if(gap==1) gap = 0;
        else gap = (gap/2) + (gap%2);
    }
}
