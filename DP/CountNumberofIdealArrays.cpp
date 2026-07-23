#include <bits/stdc++.h>
using namespace std;

/*
Count Number of Ideal Arrays
- Given two intgers n , maxValue && we have to return the number of ways to form an ideal array of length n
- An ideal array is an array of length n with following properties:
    - All elements are between 1 and maxValue
    - For every i >= 2, arr[i] % arr[i-1] == 0
*/

/*
Approach 1 : Graph of divisibility -> Memoized solution
- say maxValue is 6
    : 1-> 2 3 4 5 6
    : 2-> 4 6
    : 3-> 6
    : 4 , 5 , 6 -> 
- every edge means next is divisible by previous
- If we apply the bruteForce DFS approach , complexity would be exponential 

- We will use dp to avoid recomputing overlapping subproblems
- dp[len][last] = number of ideal arrays of length len ending with last

- base case : (len==n) return 1
- transition : for all divisors/multiples of last, add dp[len+1][divisor/multiple]

- complexity : O(n * maxValue * sqrt(maxValue))
*/
class Solution {
public:
    int N , maxVal;
    vector<vector<long long>> dp;
    const int MOD=1e9+7;

    long long dfs(int len , int last){

        if(len==N) return 1;

        if(dp[len][last]!=-1) return dp[len][last];

        long long count=0;
        for(int mul=last ; mul <= maxVal ; mul+=last ){
            count=(count+dfs(len+1 , mul))%MOD;
        }

        return dp[len][last]=count;
    }

    int idealArrays(int n, int maxValue) {
        N=n;
        maxVal=maxValue;

        dp.assign(N+1 , vector<long long>(maxVal+1 , -1));

        long long ans=0;
        for(int last=1 ; last<=maxVal ; last++){
            ans=(ans+dfs(1,last))%MOD;
        }

        return ans;
    }
};