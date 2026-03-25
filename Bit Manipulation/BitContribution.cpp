#include <bits/stdc++.h>
using namespace std;

/*
Each bit has its own contribution , independently of other bits
Used in problems where we need to count the contribution of each bit-> XOR , AND , OR of all pairs
*/

// hr kth bit ka contribution-> 2^k
/*
for each kth position check how many numbers have that bit set ( say count1)
then numbers with that bit not set=>count0=N-count1
*/

long long XORSumPairs(vector<int>& arr) {
    int n=arr.size();
    long long sum=0;

    for(int k=0;k<32;k++){
        long long count1=0;
        for(int &num:arr){
            if(num & (1LL<<k)){
                count1++;
            }
        }
        long long count0=n-count1;
        //for XOR: both the elements has to be different -> then the total pairs: count1*count0
        sum+=count1*count0*(1LL<<k);
    }
    return sum;
}

long long ANDSumPairs(vector<int>& arr) {
    int n=arr.size();
    long long sum=0;

    for(int k=0;k<32;k++){
        long long count1=0;
        for(int &num:arr){
            if(num & (1LL<<k)){
                count1++;
            }
        }
        long long count0=n-count1;
        //for AND: both the elements has to be same -> then the total pairs: count1*(count1-1)/2 
        long long allPairs=count1*(count1-1)/2;
        sum+=allPairs*(1LL<<k);
    }
    return sum;
}

long long ORSumPairs(vector<int>& arr) {
    int n=arr.size();
    long long sum=0;

    for(int k=0;k<32;k++){
        long long count1=0;
        for(int &num:arr){
            if(num & (1LL<<k)){
                count1++;
            }
        }
        long long count0=n-count1;
        //for OR: at least one element should have that bit set -> then the total pairs: nC2-count0C2
        long long allPairs=n*(n-1)/2 - count0*(count0-1)/2;
        sum+=allPairs*(1LL<<k);
    }
    return sum;
}