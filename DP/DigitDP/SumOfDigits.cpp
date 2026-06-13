#include <bits/stdc++.h>
using namespace std;

// Total sum of digits of all numbers from 0->n

class DigitDPSumDigits {
public:

    string num;

    long long dp[20][2][180];

    long long dfs(int pos,bool tight,int sum){

        if(pos==num.size())
            return sum;

        if(dp[pos][tight][sum]!=-1)
            return dp[pos][tight][sum];

        int limit=tight?(num[pos]-'0'):9;

        long long ans=0;

        for(int d=0;d<=limit;d++){

            ans+=dfs(
                pos+1,
                tight&&(d==limit),
                sum+d
            );
        }

        return dp[pos][tight][sum]=ans;
    }

    long long solve(long long n){

        num=to_string(n);

        memset(dp,-1,sizeof(dp));

        return dfs(0,1,0);
    }
};

/*
-> Digit Sum == K : base : return (sum==K)
*/