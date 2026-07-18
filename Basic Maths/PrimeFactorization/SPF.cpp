#include <bits/stdc++.h>
using namespace std;

/*
Smallest Prime Factor (SPF) Sieve
- Precompute the smallest prime factor for every number up to N
- Used for fast prime factorization
- Used when there a lot of factorization query
- Time: O(N log log N) for sieve, O(log N) per factorization (query)
*/

const int MAX=1000000; // numbers upto 10^6 or 10^7 or higher
vector<int> spf(MAX+1);

void buildSPF(){

    for(int i=0 ; i<=MAX ; i++){
        spf[i]=i;
    }

    for(int i=2 ; i*i <= MAX ; i++){
        if(spf[i]==i){
            for(int j=i*i ; j<=MAX ; j+=i){
                if(spf[j]==j){
                    spf[j]=i;
                }
            }
        }
    }
}

vector<int> factorize(int n){
    vector<int> factors;

    while(n!=1){
        factors.push_back(spf[n]);
        n/=spf[n];
    }
    
    return factors;
}