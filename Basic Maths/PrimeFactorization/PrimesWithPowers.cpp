#include <bits/stdc++.h>
using namespace std;

/*
Prime Factorization with Powers
- When you need the count of divisors or their sum
*/

vector<pair<int , int>> primeFactorsWithPower(int n){

    vector<pair<int , int>> factors;

    for(int i=2 ; i*i <= n ; i++){
        if(n%i == 0){
            int count=0;

            while(n%i == 0){
                count++;
                n/=i;
            }
            factors.push_back({i, count});
        }
    }

    if(n>1){
        factors.push_back({n, 1});
    }
    
    return factors;
}