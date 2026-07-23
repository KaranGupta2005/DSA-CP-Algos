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

/*
Approach 2: Method of Distinct Chains:
- Notice : 1 2 4 4 4 || 1 1 2 4 4 || 1 1 1 2 4 : these are different arrays , but they all come from 1->2->4 this chain
- Each such chain consists of distinct values ( say k ) , and we have to place them among n positions , such that each value appears atleast once
- Hence there are n-1 possible gaps and we have to choose (k-1) change points (where value changes , say 1->2 or 2->4)
    : this is the star and bar method / beggar's method , answer is C(n-1, k-1)

- Now , better to divide the problem into 2 parts :
    : part A : Count chains 
    : part B : Count how many arrays each chain creates : (number of chains of length len) * C(n-1, len-1)

- Since a lot of combinations values are required : will be using pascal's triangle to precompute it

- DP ON Chains:
    - dp[len][last] : number of chains of length len ending with last
    - base case : each element in range [1 , maxValue] is a chain of length 1 -> dp[1][x]
    - transition ( dp[len+1][divisor]) : for each divisor of last, add dp[len][last]

    - after this , we will have dp[len][x] for all lengths and all ending values
    - now for each length len , we will add (dp[len][x] * C(n-1, len-1)) to the answer

- Complexity : O(14 * maxValue*log(maxValue))
- How come 14??
    : maximum length of chain is 14 (1->2->4->8->16->...->2^13->2^14) , because 2^14 > 10^4
*/

class Solution {
public:
    const int MOD=1e9+7;
    const int MAX=14;

    int idealArrays(int n, int maxValue) {
        
        vector<vector<long long>> dp(MAX+1 , vector<long long>(maxValue+1 , 0));

        // counting the number of chains of length 1
        for(int i=1 ; i<=maxValue ; i++){
            dp[1][i]=1;
        }

        // counting chains of length 2,3,4...MAX+1
        for(int len=1 ; len<MAX ; len++){
            for(int last=1 ; last<=maxValue ; last++){

                if(dp[len][last]==0) continue;

                for(int mul=2*last ; mul<=maxValue ; mul+=last){
                    dp[len+1][mul]+=dp[len][last];
                    dp[len+1][mul]%=MOD;
                }
            }
        }
        
        // precomputing pascal's triangle
        vector<vector<long long>> C(n+15 , vector<long long>(15,0));

        for(int i=0 ; i<n+15 ; i++){
            C[i][0]=1;
            for(int j=1 ; j<=min(i,14) ; j++){
                if(j==i) C[i][j]=1;

                else{
                    C[i][j]=(C[i-1][j-1] + C[i-1][j])%MOD;
                }
            }
        }

        // counting how many arrays each chain creates
        long long ans=0;

        for(int len=1 ; len<=MAX ; len++ ){
            long long totalChains=0;
            for(int last=1 ; last<=maxValue ; last++){
                totalChains+=(dp[len][last]);
                totalChains%=MOD;
            }

            ans+=(totalChains * C[n-1][len-1]);
            ans%=MOD;
        }
        return ans;
    }
};

/*
Approach 3 : Prime Factorization + Combinatorics (Official Solution)

- Instead of counting divisibility chains using DP, count them directly using prime factorization.
- Suppose the last value is 360 = 2³ × 3² × 5¹

- Starting from 1 (=2⁰×3⁰×5⁰), every chain is formed by gradually increasing these exponents.

- For exponent 'cnt' of a prime, we need to distribute 'cnt' exponent increments among the n positions of the array.
- Number of ways to do this is
    : C(n-1+cnt , cnt)
Example:
    2³ contributes C(n+2,3)
    3² contributes C(n+1,2)
    5¹ contributes C(n,1)

- Prime factors are independent, so multiply the combinations for every prime exponent.

Algorithm:
- For every x from 1 to maxValue
    : Prime factorize x
    : For every exponent cnt
            ways *= C(n-1+cnt, cnt)
    : Add ways to answer

- Pascal Triangle is used to precompute all required combination values.

Complexity:
- O(maxValue * √maxValue)
- Space : O(n * 14)
*/
class Solution {
public:

    static constexpr int MOD = 1e9 + 7;

    int idealArrays(int n, int maxValue) {

        vector<vector<long long>> C(n + 15,
                                    vector<long long>(15));

        for (int i = 0; i < n + 15; i++) {

            C[i][0] = 1;

            for (int j = 1; j <= min(i, 14); j++) {

                if (j == i)
                    C[i][j] = 1;
                else
                    C[i][j] =
                        (C[i - 1][j - 1] +
                         C[i - 1][j]) % MOD;
            }
        }

        long long ans = 0;

        for (int x = 1; x <= maxValue; x++) {

            int t = x;

            long long ways = 1;

            for (int p = 2; p * p <= t; p++) {

                if (t % p == 0) {

                    int cnt = 0;

                    while (t % p == 0) {

                        cnt++;
                        t /= p;
                    }

                    ways =
                        ways *
                        C[n - 1 + cnt][cnt] %
                        MOD;
                }
            }

            if (t > 1)
                ways = ways * C[n][1] % MOD;

            ans += ways;
            ans %= MOD;
        }

        return ans;
    }
};