#include <bits/stdc++.h>
using namespace std;

// when range sum queries for a submatrix
// when the final grid is asked after applying all the operations

// assume updates[i]: [r1,c1,r2,c2,val]

// only four updates are required

vector<vector<int>> diffArray(int n , int m , vector<vector<long long>>& updates){
    // values can be large -> long long
    vector<vector<long long>> diff(n+2,vector<long long>(m+2,0)); // not n+1 , m+1 -> will handle the overflow

    for(auto &it:updates){
        int r1=it[0];
        int c1=it[1];
        int r2=it[2];
        int c2=it[3];
        int val=it[4];
        
        // first horizontal propagation , then vertical propagation
        diff[r1][c1]+=val;     // wave starts
        diff[r1][c2+1]-=val;   // stop at the right 
        diff[r2+1][c1]-=val;   // stop at the bottom
        diff[r2+1][c2+1]+=val; // at the bottom right , subtracted twice , so added back
    }

    // first prefix sum in the columns
    for(int i=0;i<=n;i++){
        for(int j=1;j<=m;j++){
            diff[i][j]+=diff[i][j-1];
        }
    }

    // then prefix sum in the rows
    for(int j=0;j<=m;j++){
        for(int i=1;i<=n;i++){
            diff[i][j]+=diff[i-1][j];
        }
    }

    // or rows first -> then columns will also work

    // final array
    vector<vector<int>> ans(n, vector<int>(m));
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            ans[i][j]=diff[i][j];

    return ans;
}

// time complexity-> O(n×m+q)
// space complexity-> O(n×m)