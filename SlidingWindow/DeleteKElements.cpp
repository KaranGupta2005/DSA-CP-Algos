#include <bits/stdc++.h>
using namespace std;

/*
Pattern (Longest Subarray / Substring / Window):
- Delete at most one element
- Delete exactly one element
- Flip / replace at most k elements
*/

int characterReplacement(string s, int k) {

    int l = 0;
    int ans = 0;
    int maxF = 0;

    vector<int> freq(26,0);

    for(int r=0;r<s.size();r++) {

        freq[s[r]-'A']++;

        maxF=max(
            maxF,
            freq[s[r]-'A']
        );

        while(
            (r-l+1)-maxF > k
        ) {
            freq[s[l]-'A']--;
            l++;
        }

        ans=max(
            ans,
            r-l+1
        );
    }

    return ans;
}