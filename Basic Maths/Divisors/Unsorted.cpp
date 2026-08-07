#include <bits/stdc++.h>
using namespace std;

vector<int> getDivisors(int n){
    vector<int> divisors;

    for(int d=1 ; 1LL*d*d <= n ; d++){
        if(n%d == 0){
            divisors.push_back(d);

            if(n/d != d){
                divisors.push_back(n/d);
            }
        }

    }
    
    return divisors;
}