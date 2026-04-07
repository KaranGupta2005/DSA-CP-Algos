#include <bits/stdc++.h>
using namespace std;

/*
- whenever you asked to build a sequence(like string , an array , etc) one b one
- there are states and transitions
- find the number of ways to build it 

Here we will apply dp on graphs
- consider the states as nodes and the transitions as edges
- the dp[i] represents the number of ways to reach node i
*/

int knightDialer(int n){
    const int MOD=1e9+7;

    // known knight moves
    vector<vector<int>> moves={
        {4, 6},    // 0
            {6, 8},    // 1
            {7, 9},    // 2
            {4, 8},    // 3
            {0, 3, 9}, // 4
            {},        // 5
            {0, 1, 7}, // 6
            {2, 6},    // 7
            {1, 3},    // 8
            {2, 4}     // 9
    };

    vector<long long>dp(10,1); // base case: length==1

    // Reverse thinking: instead of thinking what a node can lead to , think from where it can come
    for(int step=2;step<=n;step++){
        vector<long long> newDp(10,0);

        for(int i=0;i<10;i++){
            for(auto &it:moves[i]){
                newDp[it]=(newDp[it]+dp[i])%MOD;
            }
        }

        dp=newDp;
    }
    
    long long result=0;
    for(int i=0;i<10;i++){
        result=(result+dp[i])%MOD;
    }

    return result;
}

vector<int> optimized(int n){
    const int MOD=1e9+7;

    long long d0=1,d1=1,d2=1,d3=1,d4=1,d5=1,d6=1,d7=1,d8=1,d9=1;
    // base case: length==1

    for(int step=2;step<=n;step++){
        long long nd0=(d4+d6)%MOD;
        long long nd1=(d6+d8)%MOD;
        long long nd2=(d7+d9)%MOD;
        long long nd3=(d4+d8)%MOD;
        long long nd4=(d0+d3+d9)%MOD;
        long long nd5=0;
        long long nd6=(d0+d1+d7)%MOD;
        long long nd7=(d2+d6)%MOD;
        long long nd8=(d1+d3)%MOD;
        long long nd9=(d2+d4)%MOD;
        
        d0=nd0;
        d1=nd1;
        d2=nd2;
        d3=nd3;
        d4=nd4;
        d5=nd5;
        d6=nd6;
        d7=nd7;
        d8=nd8;
        d9=nd9;
    }

    long long total=(d0+d1+d2+d3+d4+d5+d6+d7+d8+d9)%MOD;

    return total;
}
// Time Complexity: O(n)
// Space Complexity: O(1)
