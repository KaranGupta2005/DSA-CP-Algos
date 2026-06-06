#include <bits/stdc++.h>
using namespace std;

/*
Count a specific digit 'd' in all non negative numbers from 0 to n

- The bruteforce suggests to loop from 0->n and then check digit by digit : O(n * log n)
- But we can do better by using digit DP or mathematical approach
- We will be tracking how many times 'd' appears at a digits position (Count Separately Ones place , tens place , etc)
eg. block=[0,9] : 1 appears one time (at ones place)
eg. block=[0,99] : 1 appears 10 times (at tens place 10 times)
eg. block=[0,999] : 1 appears 100 times (at hundreds place 100 times)

- So for every block (factor*10) digit d appears (factor) times

- For any digit position, divide n into 3 parts:
    - higher : total completed cycles = n/(factor*10)
    - curr : current state of the cycle = (n/factor)%10
    - lower : unfinished part = n%factor

- Count Contribution of digit d at this position:
    - If curr < d : contribution due to completed cycles only = higher * factor
    - If curr == d : contribution due to completed cycles + partial = higher * factor + lower + 1
    - If curr > d : contribution due to previously completed cycles + 1 full cycle = (higher + 1) * factor

- Special case when d==0:
    - higher * factor shouldn't count 0s at the start (like 000, 00, 0) : Leading zeros
    - So we subtract 1 for each position where d==0
*/

long long countDigit(long long n, int d) {

    long long ans=0;

    for(long long factor=1;factor<=n;factor*=10){
        
        long long higher=n/(factor*10);
        long long curr=(n/factor)%10;
        long long lower=n%factor;

        if(curr < d){
            ans+=(higher*factor);
        }
        else if(curr == d){
            ans+= ((higher*factor) + (lower+1));
        }
        else{
            ans+=((higher+1)*factor);
        }
    }
    
    return ans;
}

long long count0(long long n) {
    
    long long ans=0;

    for(long long factor=1 ; factor<=n ; factor*=10){
        
        long long higher=n/(factor*10);
        long long curr=(n/factor)%10;
        long long lower=n%factor;
        
        if(higher==0) continue;

        if(curr==0){
            ans += (higher - 1) * factor + lower + 1;
        }
        else{ 
            // curr > 0
            ans += higher * factor; 
        }
    }
    
    return ans;
}
