#include <bits/stdc++.h>
using namespace std;

/*
Montone Increasing String
- It looks like 0....0 | 1....1 , eg. 000000111111
- We have to think about about where to place the boundary :
    - everything before the boundary must be 0
    - everything after the boundary must be 1

Approach 1 : Prefix + Suffix Idea
- Count the ones in left and the zeros in right
- Number of flips would be min(left_ones, right_zeros) (for any position)

Approach 2 : DP
- We will maintain:
    - ones : number of ones seen so far
    - dp / flips : number of flips till current position
- Whenever you see one , ones++
- Whenever you find zero : either flip that 0->1 or flip all the ones seen so far to 0
- hence flips = min(ones, flips + 1)
*/

/*
Approach 1
Time : O(N)
Space : O(N)
*/
int minFlipsMonoIncr(string s) {
        
    int n=s.length();

    vector<int> leftOnes(n,0) , rightZeros(n,0);

    for(int i=1; i<n ; i++){
        leftOnes[i]=leftOnes[i-1]+(s[i-1]=='1');
    }

    for(int i=n-2 ; i>=0 ; i--){
        rightZeros[i]=rightZeros[i+1]+(s[i+1]=='0');
    }

    int ans=INT_MAX;
    for(int i=0 ; i<n ; i++){
        ans=min(ans , leftOnes[i]+rightZeros[i]);
    }

    return ans;
}

/*
Approach 2
Time : O(N)
Space : O(1)
*/
int minFlipsMonoIncr(string s) {
        
    int n=s.size();

    int ones=0 , flips=0;

    for(auto &it : s){

        if(it=='1') ones++;
        else{
            flips=min(flips+1 , ones);
        }
    }

    return flips;
}