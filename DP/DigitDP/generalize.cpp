#include <bits/stdc++.h>
using namespace std;

/*
Digit DP
- Whenever problem says - Find all the occurrences of numbers in a range with a constraint
- Here we will go digit by digit and try to choose digits at a position
eg. n = 357
    pos=0: Allowed digits: 0,1,2,3
         : 'tight == false'-> If we choose 0,1,2 then the overall number < n and in the next pos (pos+1) we can choose any digit from 0-9
         : 'tight == true' -> the prefix build so far == n ka prefix : if we choose 3 then in next pos we can only choose from 0-5
    Hence: limit = tight ? digit[pos] : 9;

- dp[state] = dp[pos][tight][(constraint parameters)]
- base case : when (pos==string.length()) return (valid answer? 1: 0);
*/

string num;
long long dp[20][2];

long long dfs(int pos , bool tight){

    if(pos==num.size()){
        return 1;
    }

    if(dp[pos][tight]!=-1) return dp[pos][tight];

    int limit = tight ? nums[pos]-'0' : 9;

    for(int dig=0;dig<=limit;dig++){
        
        ans+=dfs(pos+1 , tight && (dig==limit));
    }
    
    return dp[pos][tight]=ans;
}

long long count(int num){
    num = to_string(num);
    memset(dp , -1 , sizeof(dp));
    return dfs(0 , true);
}
