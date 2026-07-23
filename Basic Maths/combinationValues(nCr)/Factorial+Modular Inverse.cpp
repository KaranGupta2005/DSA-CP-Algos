#include <bits/stdc++.h>
using namespace std;

/*
Factorial + Modular Inverse
- Used when n is arbitarily large , in the order of 10^6 and there a lot of queries
- Precompute factorials and modular inverses

- nCr= n! / (r! * (n-r)!) : Mod is not possible with division , hence need to take modular inverse
- nCr = fact[n] * invFact[r] * invFact[n-r]
- Modular inverse : inverse(x) == power(x, MOD-2) % MOD : by Fermat's Little Theorem

- fact[0]=1;
  for(int i=1;i<=N;i++)
    fact[i]=fact[i-1]*i%MOD;

- invFact[N]=power(fact[N] , MOD-2);
  for(int i=N-1;i>=0;i--)
    invFact[i]=invFact[i+1]*(i+1)%MOD;

- Time : O(N)
- Space : O(N)
*/

const int MOD=1e9+7;
const int MAXN=200000;
long long fact[MAXN+1], invFact[MAXN+1];

long long power(long long a , long long b){

    long long res=1;

    while(b){
        if(b&1){
            res=(res*a)%MOD;
        }

        a=(a*a)%MOD;
        b>>=1;
    }
    
    return res;
}

void precompute(){
    fact[0]=1;
    for(int i=1;i<=MAXN;i++)
        fact[i]=fact[i-1]*i%MOD;
    
    invFact[MAXN]=power(fact[MAXN], MOD-2);
    for(int i=MAXN-1;i>=0;i--)
        invFact[i]=invFact[i+1]*(i+1)%MOD;
}

long long nCr(int n, int r){
    if(r > n || r < 0) return 0;
    return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
}



