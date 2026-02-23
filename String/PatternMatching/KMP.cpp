#include <bits/stdc++.h>
using namespace std;

// while finding whether the 'pattern' exists in 'text' or not 
// the Naive Approach is to match the characters one by one , and restart the matching from the first character of pattern and the next character of text
// this would take O(n*m) time complexity in worst case

// to avoid unnecessary comparisions  , we use KMP algorithm(Knuth-Morris-Pratt)
/*
    KMP involves basically two steps:
    1. Matching the pattern itself using the LPS(Largest Proper Prefix which is also Suffix) array
    2. Using the LPS array to match the pattern in the text
*/

// each lps[i]-> how much of the pattern can be reused after a mismatch at position i

vector<int> computeLPS(string pattern){
    int m=pattern.length();
    vector<int> lps(m,0);

    int len=0; // first char has no proper prefix==suffix
    int i=1;   // start from second char

    while(i<m){
        if(pattern[i]==pattern[len]){
            len++;
            lps[i]=len;
            i++;
        }else{
            if(len==0){
                lps[i]=0;
                i++;
            }else{
                len=lps[len-1]; // will fallback to previous longest prefix suffix match
            }
        }
    }
    return lps;
}

void patternSearch(string text, string pattern){
    int n=text.length();
    int m=pattern.length();
    
    vector<int> lps=computeLPS(pattern);
    
    int i=0 , j=0; // i-> pointer to text , j-> pointer to pattern

    while(i<n){
        if(text[i]==pattern[j]){
            i++;
            j++;
        }

        if(j==m){
            cout<<"Pattern found at index "<<i-j<<endl;
            j=lps[j-1]; // fallback to previous longest prefix suffix match for the next match
        }

        else if(i<n && pattern[j]!=text[i]){
            if(j==0){
                i++;
            }else{
                j=lps[j-1];
            }
        }
    }
}

// lps is always computed for the entire array , so the last index of the array is always the length of the longest proper prefix which is also suffix for the entire pattern
