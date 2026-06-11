#include <bits/stdc++.h>
using namespace std;

// Count numbers Having Exactly K occurences of digit X
// eg. Count all the numbers with three 6

string num;
int K;
int dp[20][2][20];

long long dfs(int pos , bool tight , int count){

    if(pos==num.length()){
        return (count==K);
    }

    if(dp[pos][tight][count]!=-1){
        return dp[pos][tight][count];
    }

    long long ans=0;

    int limit = (tight)? num[pos]-'0':9;

    for(int dig=0 ; dig<=limit ; dig++){
        ans+=dfs(pos+1 , tight && (limit==dig) , count+(dig==6));
    }

    return dp[pos][tight][count]=ans;
}

long long solve(long long n,int k){

    num=to_string(n);
    K=k;
    memset(dp,-1,sizeof(dp));

    return dfs(0,1,0);
}

/*
-> atmost K sevens : base: return (count7)<=K
-> at least K odd digits : base : retrun (countOdd)>=K
*/
