#include <bits/stdc++.h>
using namespace std;

// Rabin Karp algorithm is a pattern matching algorithm
// It matches patterns by sliding over all possible windows of a text
/*
   KMP algorithm is faster in order to find one pattern
   But Rabin Karp is better when we have to find multiple patterns
   It is used in DNA sequence analysis , plagiarism detection, document fingerprinting, etc.
*/

// in this method we don't compare strings , but instead the hash values that represent the strings
int rabinKarp(string& text, string& pattern){
    int n=text.length();
    int m=pattern.length();

    if(m>n) return -1; // pattern is longer than text , important edge case

    int base=101; // any prime number
    int mod=1e9+7; // inorder to avoid overflow

    long long patternHash=0;
    long long textHash=0;
    long long power=1;

    // base^(m-1)
    for(int i=0;i<m-1;i++){
        power=(power*base)%mod;
    }

    // initial hash values
    for(int i=0;i<m;i++){
        patternHash=(patternHash*base + pattern[i])%mod;
        textHash=(textHash*base + text[i])%mod;
    }

    // sliding window
    for(int i=0;i<=(n-m);i++){
        if(patternHash==textHash){
            // once hash values match, we compare the actual strings
            // in order to avoid collision as some substrings can have same hash values
            if(text.substr(i,m)==pattern){
                return i;
            }
        }

        // rolling hash
        // instead of recalculating hash for each window, we remove the leftmost character and add the new character
        if(i<(n-m)){
            textHash=(textHash - (text[i]*power)%mod + mod)%mod;
            textHash=(textHash*base + text[i+m])%mod;
        }
    }
    return -1;
}
