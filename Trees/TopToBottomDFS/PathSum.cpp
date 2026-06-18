#include <bits/stdc++.h>
using namespace std;

/*
Path Sum
- Given a root of a binary tree and a targetSum
- We need to find there exists a path from root->leaf where pathSum==targetSum
- The parents will be returning the remaining sum to the children 
    - (targetSum - node->val)
- When leafNode reached : 
    - Check targetSum == node->val
*/

bool hasPathSum(TreeNode* root , int targetSum){
    if(!root) return false;

    if(!root->left && !root->right){
        return (targetSum==root->val);
    }

    return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val);
}

