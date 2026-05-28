#include <bits/stdc++.h>
using namespace std;

long long power(long long a , int n , int limit){
    long long ans=1;

    while(n>0){
        if(n&1){
            if(ans>limit/a) return limit+1;
            else ans*=a;
        }

        n>>=1;

        if(n>0){
            if(a>limit/a) return limit+1;
            a*=a;
        }
    }
    
    return ans;
}
int nthRoot(int n , int x){
    long long low=1;
    long long high=x;

    int ans=-1;

    while(low<=high){
        long long mid=low+(high-low)/2;
        
        long long val=power(mid,n,x);
        
        if(val==x){
            return mid;
        }
        else if(val<x){
            ans=mid;
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    
    return ans;
}