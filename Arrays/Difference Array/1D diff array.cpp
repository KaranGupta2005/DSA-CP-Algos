#include <bits/stdc++.h>
using namespace std;

// whenever 'range sum' queries are given or when the final array is required after applying all the operations-> difference array
// for each update-> O(1)
// for forming the final array-> O(n+q)

// diff array-> to define boundaries
// prefix sum-> to apply these operations

// also called as 'differential array'

// assume updates[i]: [l,r,val]
vector<int> diffArray(int n , vector<vector<int>>& updates ){
    vector<int> diff(n,0); // can take n->n+1 to handle overflow

    for(auto &it:updates){
        int l=it[0];
        int r=it[1];
        int val=it[2];

        diff[l]+=val; // propagation starts
        if(r+1<n) diff[r+1]-=val; // propagation ends
    }

    for(int i=1;i<n;i++){
        diff[i]+=diff[i-1];
    }

    return diff;
}

// overlap , sweep line , capacity check , etc -> hidden diff array

// if the initial array is given -> original array + diff array -> final array