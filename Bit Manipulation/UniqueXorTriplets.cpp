#include <bits/stdc++.h>
using namespace std;

/*
Unique XOR Triplets

- most naive approach would be to check all possible triplets (i,j,k) where i<j<k
- and check if a[i] ^ a[j] ^ a[k] == 0
- this would be O(n^3) time complexity 
- could be optimized based on whether duplicates allowed or not

- if array is a permutation of [0,n-1] or [1,n] then there exists a property in case of Xor triplets
- if n<=2 , then only n triplets possible
- otherwise all the values from [0 , 2^k -1] are possible where k is the number of bits required to represent the n
- in order words , need to return the next higher power of 2

- if duplicates are allowed , where i<=j<=k
- a^a^a=a && a^a^b=b , a^b^b=a , etc : original numbers only
- only a^b^c will give a unique result
- Hence will find the Xor of each pair , then xor it with all elements
*/

int bruteForce(vector<int>& arr){
    int n=arr.size();

    unordered_set<int> st;

    for(int i=0 ; i<n ; i++){
        for(int j=i+1 ; j<n ; j++){
            for(int k=j+1 ; k<n ; k++){
                    st.insert(arr[i] ^ arr[j]);
            }
        }
    }
    
    return st.size();
}

// permutation
int uniqueXorTriplets(vector<int>& nums) {
        
    int n=nums.size();

    if(n<=2) return n;

    int ans=1;
    while(ans<=n){
        ans<<=1;
    }

    return ans;
}

// generic
int uniqueXorTriplets(vector<int>& nums) {
    int n=nums.size();

    if(n==1) return 1;

    unordered_set<int> pairXor ;
    unordered_set<int> ans;

    for(auto &num : nums){
        ans.insert(num);
    }

    for(int i=0 ; i<n ; i++){
        for(int j=i+1 ; j<n ; j++){
            pairXor.insert(nums[i]^nums[j]);
        }
    }

    for(auto &p : pairXor){
        for(auto &num : nums){
            ans.insert(p^num);
        }
    }

    return ans.size();
}