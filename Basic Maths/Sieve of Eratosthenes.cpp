#include <bits/stdc++.h>
using namespace std;

vector<bool> sieve(int n){
    vector<bool> primes(n+1,true);
    primes[0]=primes[1]=false;

    for(int i=2;(i*i)<=n;i++){
        if(primes[i]==true){
            int j=i*i;
        while(j<=n){
            primes[j]=false;
            j+=i;
        }
        }
    }
    return primes;
}

int main(){
    int n;
    cout<<"Enter the number between which you want to find the prime numbers: ";
    cin>>n;
    
    vector<bool> prime=sieve(n);
    for(int i=2;i<=n;i++){
        if(prime[i]){
            cout<<i<<" ";
        }
    }
    return 0;
}