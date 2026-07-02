#include <bits/stdc++.h>
using namespace std;

int peakIndexInMountainArray(vector<int>& arr) {

    int l=0;
    int r=arr.size()-1;

    while(l<=r){
        int mid=l+(r-l)/2;

        if(arr[mid]>arr[mid+1] && arr[mid]>arr[mid-1]) return mid;

        if(arr[mid]<arr[mid+1]){
            l=mid+1;
        }else{
            r=mid;
        }
    }
    return -1;
}