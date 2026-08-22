#include <bits/stdc++.h>
using namespace std;

/*
- This is also called as State Compression Segment Tree or Boundary DP Segment Tree

- Why can't normal DP work in this House Robber type problem:
    - dp[i]=max(dp[i+1], dp[i+2]+nums[i])
    - Suppose 2 7 9 3 1 -> if we change 9->100 , then dp[2] , dp[3] , dp[4] will change
    - So one update forces entire DP to be recomputed : O(n*q) complexity
    - But observe that only nearby dp states are affected 

- Normal Segment Tree is not Useful :
    - Because House Robber is not mergeable
    - Left : 4 5 , Right : 6 7 , suppose leftAns is 5 (but uses the last element) and rightAns is 7 (but uses the first element) 

- DP States
    - these depend upon the last and first elements of the subarray
    - dp[0][0] = max sum subsequence not including first and the last element
    - dp[0][1] = max sum subsequence not including first element , inc last element
    - dp[1][0] = max sum subsequence not including last element , inc first element
    - dp[1][1] = max sum subsequence including last element , first element

    - only boundary matters (as only they can touch) (leftLast ... rightFirst): these are adjacent

- Leaf Node (Single element)
    - dp[0][0]=0
    - dp[1][1]=nums[i]
    - dp[0][1]==dp[1][0]==-INF (not possible as only one element and first==last)

- Merge
    - check for all the 16 combinations , only (leftLast && rightFirst) is conflict so continue;

- Whenever you see Queries : update i and answer after every query ; and DP depends only on nearby elements : Segment Tree + DP States
*/

class Solution {
public:
    const int MOD=1e9+7;
    const long long NEG=-4e18;

    struct Node{
        long long dp[2][2];
    };

    vector<Node> seg;

    Node merge(Node &L , Node &R){
        Node res;

        for(int i=0 ; i<2 ; i++){
            for(int j=0 ; j<2 ; j++){
                res.dp[i][j]=NEG;
            }
        }

        for(int lf=0 ; lf<2 ; lf++){
            for(int ll=0 ; ll<2 ; ll++){
                for(int rf=0 ; rf<2 ; rf++){
                    for(int rl=0 ; rl<2 ; rl++){

                        if(ll && rf) continue;

                        res.dp[lf][rl]=max(res.dp[lf][rl] , L.dp[lf][ll]+R.dp[rf][rl]);
                    }
                }
            }
        }

        return res;
    }

    void build(int idx , int l , int r , vector<int>& nums){
        if(l==r){
            for(int i=0 ; i<2 ; i++){
                for(int j=0 ; j<2 ; j++){
                    seg[idx].dp[i][j]=NEG;
                }
            }

            seg[idx].dp[0][0]=0;
            seg[idx].dp[1][1]=max(0 , nums[l]);
            return;
        }

        int mid=(l+r)/2;

        build(2*idx , l , mid , nums);
        build(2*idx+1 , mid+1 , r , nums);

        seg[idx]=merge(seg[2*idx] , seg[2*idx + 1]);
    }

    void update(int idx , int l , int r , int pos , int val){
        if(l==r){
            for(int i=0 ; i<2 ; i++){
                for(int j=0 ; j<2 ; j++){
                    seg[idx].dp[i][j]=NEG;
                }
            }

            seg[idx].dp[0][0]=0;
            seg[idx].dp[1][1]=max(0 , val);
            return;
        }

        int mid=(l+r)/2;

        if(pos<=mid){
            update(2*idx , l , mid , pos , val);
        }
        else{
            update(2*idx +1 , mid+1 , r , pos , val);
        }

        seg[idx]=merge(seg[2*idx] , seg[2*idx +1]);
    }

    int maximumSumSubsequence(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();

        seg.resize(4*n + 5);

        build(1 , 0 , n-1 , nums);

        long long ans=0;

        for(auto &q:queries){
            update(1 , 0 , n-1 , q[0] , q[1]);

            long long best = 0;

            for (int i = 0; i < 2; i++)
                for (int j = 0; j < 2; j++)
                    best = max(best, seg[1].dp[i][j]);

            ans = (ans + best) % MOD;
        }

        return ans;
    }
};