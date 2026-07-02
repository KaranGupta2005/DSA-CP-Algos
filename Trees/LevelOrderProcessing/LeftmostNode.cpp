#include <bits/stdc++.h>
using namespace std;

/*
Leftmost Node of the Last Level
- We need to find the first node of the last level
- Last Level : MaxDepth
*/

int ans;
int maxDepth;

void helper(TreeNode* root, int depth){
    if(!root) return;
    
    if(depth > maxDepth){
        maxDepth = depth;
        ans = root->val;
    }
    
    helper(root->left, depth + 1);
    helper(root->right, depth + 1);
}

int findBottomLeftValue(TreeNode* root){
    if(!root) return -1;
    maxDepth=-1;

    helper(root , 0);
    return ans;
}

// BFS Approach
