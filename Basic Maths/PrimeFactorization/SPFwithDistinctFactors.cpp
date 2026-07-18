#include <bits/stdc++.h>
using namespace std;

int MAX=1000000;
vector<int> spf(MAX);

void buildSPF(){

    for(int i=0 ; i<=MAX ; i++){
        spf[i]=i;
    }

    for(int i=2 ; i*i <= MAX ; i++){
        if(spf[i]==i){
            for(int j=i*i ; j <= MAX ; j+=i){
                if(spf[j]==j){
                    spf[j]=i;
                }
            }
        }
    }
}

vector<int> factorize(int n){
    vector<int> factors;

    while(n>1){
        int p=spf[n];

        factors.push_back(p);
        
        while(n%p==0){
            n/=p;
        }
    }
    
    return factors;
}
