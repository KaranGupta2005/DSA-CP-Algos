#include <bits/stdc++.h>
using namespace std;

/*
Type 4: Days/Threshold Type
- minimize the day required to form m bouquets with k adjacent flowers
- we will be finding the first true : 'min'
*/

bool canMake(vector<int>& arr, int m, int k, int day){
    int count=0 , flowers=0;

    for(int x:arr){
        if(x<=day){
            flowers++;
            if(flowers==k){
                count++;
                flowers=0;
            }
        }
        else{
            flowers=0;
        }
    }
    
    return count>=m;
}

int minDays(vector<int>& bloomDay, int m, int k) {
    int n = bloomDay.size();

    // impossible case
    if(n < 1LL*m*k) return -1;

    int low=*min_element(bloomDay.begin(),bloomDay.end()); // minimum possible day
    int high=*max_element(bloomDay.begin(),bloomDay.end()); // maximum possible day

    int ans=high;

    while(low<=high){
        int mid=low+(high-low)/2;
        if(canMake(bloomDay,m,k,mid)){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }

    return ans;
}
