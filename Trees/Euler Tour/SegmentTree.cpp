#include <bits/stdc++.h>
using namespace std;

/*
Segment Trees
- Euler Tour is used same as that with Fenwick Tree : for passing euler order into queries
- It is helpful with sum queries , xor queries , min/max queries , gcd/lcm queries , bitwise and/or queries , etc.
- The entire template remains same for each case , only the merging step changes.
*/

// Sum Queries
class SegmentTree {
    vector<int> tree;
    int n;

    public:
    SegmentTree(vector<int>& arr){
        n=arr.size();
        tree.resize(4*n);
        build(1,0,n-1,arr);
    }

    void build(int node , int l , int r , vector<int>& arr){
        if(l==r){
            tree[node]=arr[l];
            return;
        }

        int mid=(l+r)/2;
        build(2*node , l , mid , arr);
        build(2*node+1 , mid+1 , r , arr);
        tree[node]=tree[2*node]+tree[2*node+1]; // merging step
    }

    void update(int node , int l , int r , int idx , int val){

        if(l==r){
            tree[node]=val;
            return;
        }

        int mid(l+r)/2;
        if(idx<=mid){
            update(2*node , l , mid , idx , val);
        }
        else{
            update(2*node+1 , mid+1 , r , idx , val);
        }

        tree[node]=tree[2*node]+tree[2*node+1]; // merging step
    }

    int query(int node , int l , int r , int ql , int qr){

        if(l>qr || r<ql){
            return 0; // identity element 
        }
        
        if(ql<=l && r<=qr){
            return tree[node];
        }

        int mid=(l+r)/2;

        return query(2*node , l , mid , ql , qr) + query(2*node+1 , mid+1 , r , ql , qr); // return merged result
    }
};

/*
Time Complexity:
- Build: O(n)
- Update: O(log n)
- Query: O(log n)
Space Complexity: O(4n)

left -> 2*node
right -> 2*node+1

XOR Queries :
- merge step : tree[node] = tree[left] ^ tree[right]
- identity element : 0
- result : leftAns^rightAns

Max Queries :
- merge step : tree[node] = max(tree[left] , tree[right])
- identity element : INT_MIN
- result : max(leftAns , rightAns)


Min Queries :
- merge step : tree[node] = min(tree[left] , tree[right])
- identity element : INT_MAX
- result : min(leftAns , rightAns)

GCD Queries :
- merge step : tree[node] = __gcd(tree[left] , tree[right])
- identity element : 0
- result : __gcd(leftAns , rightAns)

LCM Queries :
- merge step : tree[node] = lcm(tree[left] , tree[right])
- identity element : 1
- result : lcm(leftAns , rightAns)

AND Queries :
- merge step : tree[node] = tree[left] & tree[right]
- identity element : INT_MAX
- result : leftAns & rightAns

OR Queries :
- merge step : tree[node] = tree[left] | tree[right]
- identity element : 0
- result : leftAns | rightAns
*/
