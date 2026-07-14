#include <bits/stdc++.h>
using namespace std;

/*
Number of Subsequences with Different GCDs
- Possible values of gcd : (maximum element)+1 
- vector<bool> present(maxi+1 , false) : to check whether a gcd is possible or not

- Firstly mark all the elements as true in the given array
- Then for each gcd value from 1 to maximum : check for every multiple of g ( coz they can only have gcd==g )
- if currGCD==g : then it is a valid subsequence with gcd==g : break
*/

int gcd(int a , int b){
    if(b==0) return a;
    return gcd(b , a%b);
}

int countDifferentSubsequencesGCDs(vector<int>& nums) {
    
    int maxi=*max_element(nums.begin() , nums.end());
    
    vector<bool> present(maxi+1 , false);

    for(int &num : nums) {
        present[num] = true;
    }

    int ans=0;

    for(int g=1 ; g<=maxi ; g++) {
        int currGCD=0;

        for(int mul=g ; mul<=maxi ; mul+=g){
            if(!present[mul]) continue;

            currGCD=gcd(currGCD , mul);

            if(currGCD==g){
                ans++;
                break;
            }
        }
    }

    return ans;
}

/*
Complexity:

- Outer Loop : M
- Inner Loop : log M * log M ( for gcd calc )

- Space : O(M)
- Time : O(M * log M * log M)
*/
