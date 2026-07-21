#include <bits/stdc++.h>
using namespace std;

/*
Minimum Swaps To Make Strings Equal
- Here we can swap any element of s1 with that of s2
- Core intuition lies on counting the number of mismatches. There are only 2 kinds.
    - Type 1 (xy): s1[i] = 'x' and s2[i] = 'y'
    - Type 2 (yx): s1[i] = 'y' and s2[i] = 'x'

- Case 1: Two xy mismatches
Eg: s1 = "xx" , s2 = "yy"

s1 :   x x
s2 :   y y

      xy xy

    : One swap fixes both.
    : 2 xy mismatches → 1 swap
    : 4 xy mismatches → 2 swaps
    : 6 xy mismatches → 3 swaps
- Hence xy / 2

- Case 2: Two yx mismatches

s1 : y y
s2 : x x

2 mismatches → 1 swap
- Hence yx / 2

- Case 3: One xy and one yx
eg. s1 = xy, s2 = yx
    : Index 0: s1 = x, s2 = y -> xy mismatch
    : Index 1: s1 = y, s2 = x -> yx mismatch
- Need 2 swaps.

- Suppose : xy = 5 ; yx = 3
- First pair the same types.
    - 5 xy -> 2 pairs -> 1 leftover
    - Cost : 2 swaps

    - 3 yx -> 1 pair -> 1 leftover
    - Cost : 1 swap

- Now leftovers are 1 xy , 1 yx : Need 2 more swaps
- Formula : xy/2 + yx/2 + 2*(xy%2)

- After pairing, xy can only leave 0 or 1 mismatch.
- If xy is odd, then yx must also be odd (otherwise xy + yx would be odd and the answer is -1).
*/

    int minimumSwap(string s1, string s2) {
        
        int n=s1.size();

        int xy=0 , yx=0;

        for(int i=0 ; i<n ; i++){
            if(s1[i]==s2[i]) continue;

            if(s1[i]=='x') xy++;
            else yx++;
        }

        if((xy + yx)%2) return -1;

        return (xy/2 + yx/2 + 2*(xy%2));
    }