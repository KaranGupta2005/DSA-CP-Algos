#include <bits/stdc++.h>
using namespace std;

/*
Trial Division
- works fine when we have single or few numbers
- Complexity : O(√n) for a single number
*/

vector<int> primeFactors(int n){
    vector<int> factors;

    for(int i=2 ; i*i <= n ; i++){
        while(n%i==0){
            factors.push_back(i);
            n/=i;
        }
    }

    // prime factor > sqrt(n)
    if(n>1) factors.push_back(n);
    
    return factors;
}
