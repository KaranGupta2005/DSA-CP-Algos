#include <bits/stdc++.h>
using namespace std;

/*
Alternating Binary String
- There are only 2 possible alternating strings of length n:
    - Starting with 0: 010101...
    - Starting with 1: 101010...
- So simply we will compare each character with both of them and return the minimum swaps required

- Edge Case:
    - If the difference between number of 0s and 1s is greater than 1, then it's impossible to make alternating string
*/

    int minSwaps(string s) {

        int n = s.size();

        int ones = 0, zeros = 0;
        int mismatch0 = 0;   

        for (int i = 0; i < n; i++) {
            if (s[i] == '1') ones++;
            else zeros++;

            if (s[i] != (i % 2 == 0 ? '0' : '1'))
                mismatch0++;
        }

        if (abs(ones - zeros) > 1)
            return -1;

        if (zeros > ones)
            return mismatch0 / 2;

        if (ones > zeros)
            return (n - mismatch0) / 2;

        return min(mismatch0, n - mismatch0) / 2;
    }

