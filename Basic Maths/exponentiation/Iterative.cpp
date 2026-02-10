#include <bits/stdc++.h>
using namespace std;

double power(double a, int n){
    long long pow=n; // n might be negative and n==INT_MIN , the int range overflows

    if(pow<0){
        a=1.0/a;
        pow=-pow;
    }

    double ans=1.0;

    while(pow>0){
        if(pow&1){
            ans*=a;
        }
        a*=a;
        pow>>=1;
    }
    
    return ans;
}

long long powMod(long long a, long long n, long long mod){
    //take mod after each multiplication to avoid overflow
    long long ans=1;

    while(n>0){
        if(n&1){
            ans=(ans*a)%mod;
        }
        a=(a*a)%mod;
        n>>=1;
    }
    
    return ans;
}

// a^(-1) mod m = a^(m-2) mod m (by Fermat's Little Theorem)
// only works when m is prime and hcf(a,m) = 1
long long modularInverse(long long a, long long mod){
    return powMod(a, mod - 2, mod);
}

long long negPowerMod(long long a, long long n, long long mod){
    // for negative powers, we need modular inverse
    // a^(-n)%m = (a^(-1))^n % m
    long long inv=modularInverse(a, mod);
    return powMod(inv, n, mod);
}

int main() {
    long long a, n, mod;
    cin >> a >> n >> mod;

    if (n == 0) {
        cout << 1 << endl;
    }
    else if (n > 0) {
        cout << powMod(a, n, mod) << endl;
    }
    else {
        // n < 0
        cout << negPowerMod(a, -n, mod) << endl;
    }

    return 0;
}

// better than the recursive approach because of no recursion stack overhead and stack overflow issues
// time complexity: O(log n)
// space complexity: O(1)

