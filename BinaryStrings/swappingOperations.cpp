#include <bits/stdc++.h>
using namespace std;

/*

| Operations                      | Goal        | Final Formula                                       | Intuition                                                               |
| ------------------------------- | ----------- | --------------------------------------------------- | ----------------------------------------------------------------------- |
| `00 → 10`, `10 → 01`            | **Maximum** | If `z>0`: one `0` at `firstZero + z - 1`, rest `1`s | `00→10` reduces zeros to one; `10→01` lets the surviving `0` move left. |
| `00 → 10`, `10 → 01`            | **Minimum** | Original string                                     | Every allowed move increases the binary value, so don't perform any.    |
| `11 → 01`, `01 → 10` *(mirror)* | **Maximum** | Original string                                     | Every move decreases the binary value.                                  |
| `11 → 01`, `01 → 10` *(mirror)* | **Minimum** | If `o>0`: one `1` at `lastOne - o + 1`, rest `0`s   | `11→01` reduces ones to one; `01→10` moves the survivor right.          |
| `00 → 01`, `01 → 10`            | **Maximum** | If `z>0`: one `0` at `lastZero - z + 1`, rest `1`s  | Zeros merge; surviving `0` moves right.                                 |
| `00 → 01`, `01 → 10`            | **Minimum** | Original string                                     | Allowed moves only increase the value.                                  |
| `11 → 10`, `10 → 01`            | **Maximum** | Original string                                     | Allowed moves only decrease the value.                                  |
| `11 → 10`, `10 → 01`            | **Minimum** | If `o>0`: one `1` at `firstOne + o - 1`, rest `0`s  | Ones merge; surviving `1` moves left.                                   |
| `01 → 10` only                  | **Maximum** | `1^o 0^z`                                           | Swap until all `1`s are on the left.                                    |
| `01 → 10` only                  | **Minimum** | Original string                                     | Every swap increases the value.                                         |
| `10 → 01` only                  | **Maximum** | Original string                                     | Every swap decreases the value.                                         |
| `10 → 01` only                  | **Minimum** | `0^z 1^o`                                           | Swap until all `0`s are on the left.                                    |
| `01 ↔ 10` (both swaps allowed)  | **Maximum** | `1^o 0^z`                                           | Freely reorder by adjacent swaps.                                       |
| `01 ↔ 10` (both swaps allowed)  | **Minimum** | `0^z 1^o`                                           | Freely reorder by adjacent swaps.                                       |

eg. Maximum Binary String After Change
*/

string maximumBinaryString(string binary) {
    int n=binary.size();
    int zeros=0;
    int first=-1;

    for(int i=0 ; i<n ; i++){
        if(binary[i]=='0'){
            zeros++;

            if(first==-1) first=i;
        }
    }

    if(zeros==0) return binary;

    string ans(n,'1');
    ans[first+zeros-1]='0';

    return ans;
}