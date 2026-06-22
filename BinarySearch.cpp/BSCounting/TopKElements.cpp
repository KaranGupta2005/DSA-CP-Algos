#include <bits/stdc++.h>
using namespace std;

/*
Picking Top K elements when sequences are in AP
- Max Heap may work with smaller constraints but will give TLE on larger ones
- Binary Search on Answer for a given threshold
eg. 
Sequence: 20 17 14 11 8 5 2
Question: How many rewards ≥ 8 ? : 5
- General Formula for N : (a + (n-1)*d) >= X
                        : (first(a) - threshold(X))/diff(d) + 1
- As the threshold decreases, the count increases , hence monotonic
- We want largest T such that atleast K elements are >= T , but if less than K elements > T : T is the Kth largest value
- Last element : a+(count-1)*d
- Sum computation : count*(last-first)/2;

Procedure:
- Binary search on the answer (threshold T)
- For each mid, compute how many elements ≥ T using the formula
- T = high
- Firstly count the values > T and sum them ( for each sequence )
- If count < K, then the remaining elements are T itself
- totalSum+=(remaining)*T
*/
long long countGE(vector<int>& value , vector<int>& decay , long long T){
    long long count=0;
    int n=value.size();

    for(int i=0 ; i<n ; i++){
        long long a=value[i];
        long long d=decay[i];

        if(a < T) continue;
        count+= (a-T)/d + 1;
        count=min(count , (long long)4e18);
    }
    return count;
}
int maxTotalValue( vector<int>& value , vector<int>& decay , int m){
    const long long MOD=1e9+7;

    int n=value.size();

    long long low=1;
    long long high=1e9;

    while(low <= high){
        long long mid= low + (high-low)/2;

        if(countGE(value , decay , mid) >=m){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }

    long long T=high;

    long long totalSum=0;
    long long count=0;

    for(int i=0 ; i<n ; i++){
        long long a=value[i];
        long long d=decay[i];

        if(a < T) continue;

        long long elements = (a-(T+1))/d + 1;
        if(elements <= 0) continue;
        
        long long last = a + (elements-1)*d;
        long long sum = elements * (a + last) / 2;

        totalSum+=sum;
        count+=elements;
    }

    long long remaining = ( m - count );
    totalSum += remaining * T;
    
    return (int)(totalSum % MOD);
}
