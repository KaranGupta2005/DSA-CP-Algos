#include <bits/stdc++.h>
using namespace std;

/*
Pascal Triangle Method

- Used when the value of n is in the order of some thousands , value of r is relatively small and a lot of combination values are required
- Used when n<= 2000 ( or around 10000 ) 
    : Largest exponent of any prime in 10000 is (2^13)
    : 2^14 > 10000 , so r<=14 ( only 15 columns are required )
- No modular inverse is required

- Base case : nC0 == nCn == 1
- Recurrence relation : nCr= (n-1)C(r-1) + (n-1)C(r)
    : any value is the sum of the above two values

- Time Complexity : O(n*r)
- Space Complexity : O(n*r)
*/

const int MOD=1e9+7;
const int MAXN=10005;

vector<vector<long long>> C(MAXN , vector<long long>(20 , 0));

void precompute(){

    for(int i=0 ; i<=MAXN ; i++){
        C[i][0]=1;

        for(int j=1 ; j<=min(i , 19) ; j++){
            if(i==j) C[i][j]=1;

            else C[i][j]=(C[i-1][j-1] + C[i-1][j])%MOD;
        }
    }
    
}