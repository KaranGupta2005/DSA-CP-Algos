#include <bits/stdc++.h>
using namespace std;

// just like in 1D prefix sum- we calculate the sum from 0->i ; in 2D prefix sum we calculate the sum of rectangles from (0,0)->(i,j)

vector<vector<int>> prefixSum(vector<vector<int>>& grid) {
    int rows=grid.size();
    int cols=grid[0].size();

    vector<vector<int>> prefix(rows+1,vector<int>(cols+1,0));
    // 1 based indexing to ensure no boundary checks

    for(int i=1;i<=rows;i++){
        for(int j=1;j<=cols;j++){
            prefix[i][j]=grid[i-1][j-1]+prefix[i-1][j]+prefix[i][j-1]-prefix[i-1][j-1];
            // formula= current element+above+left-diagonal(coz added twice)
        }
    }
    return prefix;
}

int query(vector<vector<int>>& prefix,int r1 , int c1 , int r2 , int c2) {
    int curr=prefix[r2+1][c2+1];
    int above=prefix[r1][c2+1];
    int left=prefix[r2+1][c1];
    int repeat=prefix[r1][c1];
    
    int sum=curr-above-left+repeat;
    //diagonal subtracted twice so add it once
    return sum;
}
