#include <bits/stdc++.h>
using namespace std;

vector<bool> sieve(int n){
    vector<bool> primes(n+1,true);
    primes[0]=primes[1]=false;

    for(int i=2;(i*i)<=n;i++){
        if(primes[i]){
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
    int low , high;
    cout<<"Enter the lower and upper limit:";
    cin>>low>>high;

    int limit=sqrt(high); // sqrt return double value
    vector<bool> prime=sieve(limit);
    vector<int> basePrimes;
    for(int i=2;i<=limit;i++){
        if(prime[i]){
            basePrimes.push_back(i);
        }
    }

    vector<bool> segSieve(high-low+1,true);
    if(low==0){ // if 0 is present , then 1 might be present
        if(high>=0) segSieve[0]=false;
        if(high>=1) segSieve[1]=false; 
    }
    if(low==1){ 
        segSieve[0]=false; 
    }

    for(auto it:basePrimes){
        int firstMul=(low/it)*it;
        if(firstMul<low) firstMul+=it;

        for(int j=max(firstMul,it*it);j<=high;j+=it){
            segSieve[j-low]=false;
        }
    }

    for(int i=0;i<high-low+1;i++){
        if(segSieve[i]){
            cout<<i+low<<" ";
        }
    }
    
    return 0;
}