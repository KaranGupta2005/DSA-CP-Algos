#include <bits/stdc++.h>
using namespace std;

/*
- Two numbers i , j can have i*j == perfect square only when they have same square free part
- 4	2²	1
- 8	2³	2
- 9	3²	1
- So we will group numbers with same square free part and sum their values
*/

int squareFree(int x){

    int res=1;

    for(int i=2 ; i*i<=x ; i++){
        int count=0;

        while(x%i==0){
            x/=i;
            count++;
        }

        if(count%2==1) res*=i;
    }

    if(x>1) res*=x;
    
    return res;
}

long long maximumSum(vector<int>& nums){
    
    int n=nums.size();

    unordered_map<int , long long>mp ; // { square free , sum }

    for(int i=1 ; i<=n ; i++){
        int key=squareFree(i);
        mp[key]+=nums[i-1];
    }
    
    long long res=0;
    for(auto &it:mp){
        res=max(res,it.second);
    }
    
    return res; 
}
