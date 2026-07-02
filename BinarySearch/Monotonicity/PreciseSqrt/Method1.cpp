#include <bits/stdc++.h>
using namespace std;

/*
- Binary Search can also be applied on monotonic functions-> continuously increasing/decreasing
- Can also be used to find the transition point
- Here , if mid*mid<=x ( smaller values also satisfies the condition ) -> find the last true
*/

int sqrtInt(int x){
    int low=0;
    int high=x;

    int ans=0;

    while(low<=high){
        int mid=low+(high-low)/2;

        if(mid*mid<=x){
            ans=mid;
            low=mid+1;
        }else{
            high=mid-1;
        }
    }

    return ans;
}

// incremental refinement
double precision(int x , int prec , int tempSol){
    double ans=tempSol;
    double factor=1;

    for(int i=0;i<prec;i++){
        factor/=10;

        for(double j=ans;(j*j)<x;j+=factor){
            ans=j;
        }
    }

    return ans;
}