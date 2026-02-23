#include <bits/stdc++.h>
using namespace std;

// the bruteforce approach , would be to merge the two sorted arrays and then find the median
// it will take O(n+m) time -> we can improve by reducing it to O(log(min(n,m)))
// This is called as Binary Search Partition method

void findMedian(vector<int>& arr1, vector<int>& arr2) {
    int n=arr1.size();
    int m=arr2.size();
    int len=n+m;

    int target=(len+1)/2; // the number of elements on the left side of the partition -> in case of both odd and even 
    
    // always apply binary search on the smaller array for efficiency
    if(n>m){
        return findMedian(arr2,arr1);
    }

    // search space-> 0 to n
    int low=0;
    int high=n;
    while(low<=high){
        int mid1=low+(high-low)/2;
        int mid2=target-mid1;

        // l1>=r2 and l2>=r1 for the arrays to be correctly partitioned(sorted manner)
        // l1,l2 and r1,r2 are not compared since they belong to the same array
        int l1=(mid1==0)?INT_MIN:arr1[mid1-1];
        int l2=(mid2==0)?INT_MIN:arr2[mid2-1];
        int r1=(mid1==n)?INT_MAX:arr1[mid1];
        int r2=(mid2==m)?INT_MAX:arr2[mid2];

        if(l1>r2){ // move left in arr1
            low=mid1+1;
        }else if(l2>r1){ // move right in arr1
            high=mid1-1;
        }else{
            // Found the correct partition
            if(len%2==1){
                return max(l1, l2);
            }else{
                return (max(l1, l2) + min(r1, r2)) / 2.0;
            }
        }
    }
    //should never reach here
    return 0;
}
