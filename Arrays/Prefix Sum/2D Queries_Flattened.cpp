#include <bits/stdc++.h>
using namespace std;

//using the flattened array for storing prefix sums of the matrix reduces the storage look-up overhead

vector<int> flatten(vector<vector<int>>& grid) {
    int rows=grid.size();
    int cols=(rows)?grid[0].size():0;

    if(rows==0 || cols==0) return {};

    vector<int> flattened((rows+1)*(cols+1), 0);

    for(int i=1;i<=rows;i++){
        for(int j=1;j<=cols;j++){
            int idx=(i*(cols+1))+j;
            int curr=grid[i-1][j-1];
            int above=flattened[idx-(cols+1)];
            int left=flattened[idx-1];
            int diagonal=flattened[(i-1)*(cols+1)+(j-1)];

            flattened[idx]=curr+above+left-diagonal;
        }
    }
    return flattened;
}

int getRangeSum(vector<int>& flattened, int row1, int col1, int row2, int col2) {
    int cols=flattened.size();

    int curr=flattened[(row2+1)*(cols)+(col2+1)];
    int above=flattened[(row1)*(cols)+(col2+1)];
    int left=flattened[(row2+1)*(cols)+(col1)];
    int repeat=flattened[(row1)*(cols)+(col1)];
    
    return curr - above - left + repeat;
}
