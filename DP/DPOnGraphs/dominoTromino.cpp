#include <bits/stdc++.h>
using namespace std;

/*
we are given a (2*n) board , hence there are 2 rows there and n columns
- the first col can be filled by 1 domino placed vertically , hence dp[1]=1
- two cols can be filled either by placing 2 domino vertically or 2 domino horizontally , hence dp[2]=2
- three cols
(first col) + (2 columns)= dp[1]+dp[2]+...
 if we have used a after the first column , a gap state would be introduced
- gap can be present either on the above or below -> symmetry
- gap state on the ith position depends upon gap[i-1] and dp[i-2] 
- in a valid state , there can be only 1 gap in a column

therefore we conclude that
- adding of vertical domino -> dp[n-1]
- adding of horizontal domino -> dp[n-2]
- adding of tromino -> 2 * gap[n-1]

and gap[i]=gap[i-1]+dp[i-2]
*/

int numTilings(int n) {
    vector<int> dp(n+1,0);
    vector<int> gap(n+1,0);

    dp[0]=1; // there is exactly one way to fill an empty board
    dp[1]=1;
    dp[2]=2;

    gap[2]=1;

    for(int col=3;col<=n;col++){
        dp[col]=dp[col-1]+dp[col-2]+2*gap[col-1];
        gap[col]=gap[col-1]+dp[col-2];
    }
    
    return dp[n];
}
// Time Complexity:O(n)
// Space Complexity:O(n)