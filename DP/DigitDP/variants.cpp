#include <bits/stdc++.h>
using namespace std;

// Count numbers containing at least one 'l'
// introduce one more state : foundOne : to track whether 1 has appeared or not

string num;
long long dp[20][2][2];

long long dfs(int pos, bool tight, bool foundOne) {
    
    //base
    if(pos==num.size()){
        return foundOne;
    }

    if(dp[pos][tight][foundOne] != -1){
        return dp[pos][tight][foundOne];
    }

    long long ans=0;

    int limit = tight ? num[pos]-'0' : 9;

    for(int i=0;i<=limit;i++){
        
        ans+=dfs(pos+1 ,
                 tight && (i==limit),
                 // update constraint
                 foundOne || (i==1)
                 );
    }
    
    return ans;
}

long long atLeastOne(int n){
    num=to_string(n);
    memset(dp,-1,sizeof(dp));
    return dfs(0,true,false);
}
