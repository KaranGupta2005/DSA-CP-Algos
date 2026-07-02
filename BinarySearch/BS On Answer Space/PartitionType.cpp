#include <bits/stdc++.h>
using namespace std;

/*
Type 2- Partition Type:
- minimize the maximum load / sum
- we need to find the first true -> "min"
- Intuition: 
    - can we split the array into <=k parts such that : each part sum <= maxSum
    - We will keep adding the elements until the limit breaks
    - then we will increase the count and start a new partition
*/

bool canSplit(vector<int>& arr , int k , int maxSum){
    int count=1;
    int sum=0;

    for(auto &x:arr){
        // impossible case
        if(x>maxSum) return false;

        if((sum+x)>maxSum){
            count++;
            sum=x;

            // early stopping
            if(count>k) return false;
        }else{
            sum+=x;
        }
    }
    
    return true;
}

int partitionType(vector<int>& arr , int k){
    int low=*max_element(arr.begin(),arr.end()); // minimum possible answer : largest element : each element in separate partition
    int high=accumulate(arr.begin(),arr.end(),0); // maximum possible answer : sum of all elements : single partition

    int ans=high;

    while(low<=high){
        int mid=low+(high-low)/2;

        if(canSplit(arr,k,mid)){
            ans=mid;
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    
    return ans;
}
