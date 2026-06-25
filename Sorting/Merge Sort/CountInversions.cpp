#include <bits/stdc++.h>
using namespace std;

/*
Count Inversions
- An inversion is : (i<j) : arr[i] > arr[j]
- Bruteforce : Check all the pairs ( i: 0->n (outer loop) && j: i+1->n (inner loop)) (i<j) : O(n^2)
- Optimized : Using Merge Sort : O(n log n)
- During merge sort , before merging , both the halves are sorted 
- So when nums[i] > nums[j] , then all the remaining elements in the left half will also be greater since left half is sorted
- Contribution : inv += (mid - i + 1)

Intuition
- Divide the array into two halves 
- Count inversions in left half + right half + inversions between left and right half while merging
- Return the sum

*/

long long merge(vector<int>& arr , int l , int mid , int r){
    vector<int> temp;

    int i=l , j=mid+1;
    long long inv=0;

    while(i<=mid && j<=r){
        if(arr[i] <= arr[j]){
            temp.push_back(arr[i++]);
        }else{
            inv+= (mid - i + 1);
            temp.push_back(arr[j++]);
        }

    }
    
    while(i<=mid){
        temp.push_back(arr[i++]);
    }
    
    while(j<=r){
        temp.push_back(arr[j++]);
    }
    
    for(int k=l;k<=r;k++){
        arr[k]=temp[k-l];
    }
    
    return inv;
}

long long mergeSort(vector<int>& arr , int l , int r){
    if(l >= r) return 0;

    int mid=l+(r-l)/2;

    long long inv=0;
    inv+=mergeSort(arr , l , mid);
    inv+=mergeSort(arr,mid+1,r);

    inv+=merge(arr , l , mid , r);

    return inv;

}
long long inversionCount(vector<int>& arr){
    return mergeSort(arr , 0 , arr.size()-1);
}