#include <bits/stdc++.h>
using namespace std;

// This is called as 'Factorial Number System' or the 'Factoradic Trick'
// We will not be generating all the permutations , instead we will directly find out the kth permutation
/*Pattern :
    Find out the kth permutation 
    Kth permutation if the array is sorted
    Lexicographically smallest permutation
*/ 

// each position is the leader for (n-1)!
// similiarly kth position is the leader for (n-k)! permutations

void helper(vector<int>& nums , int k , int fact , string& ans){
    if(nums.empty()) return;

    int idx=k/fact; // finding the idx of the digit 
    ans+=(nums[idx]+'0');
    nums.erase(nums.begin()+idx); // removing the digit from the array

    k-=(idx*fact); // updating k

    if(!nums.empty())
    helper(nums , k ,fact/(nums.size()) , ans);
    }
string getPermutation(int n, int k) {
    vector<int> arr;

    int fact=1;
    for(int i=1;i<=n;i++){
        arr.push_back(i);
        fact*=i;
        }
    
    // fact-> n!
    k--; // for 0 based indexing
    string ans="";

    helper(arr , k , fact/n , ans);

    return ans;
}