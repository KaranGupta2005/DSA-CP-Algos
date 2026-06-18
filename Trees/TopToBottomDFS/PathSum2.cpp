#include <bits/stdc++.h>
using namespace std;

/*
- Instead of just checking whether any path exists , we need to find all the paths whose pathSum == targetSum
- This is Top-To-Bottom DFS + Backtracking
- at the start of the path -> path.push_back(node->val)
- at the end of the path , just before returning -> path.pop_back()
- here the parent sends remaining sum , current path to the children
*/

vector<vector<int>> ans;

void helper(TreeNode* root, int targetSum, vector<int>& path) {

    if(!root) return;

    path.push_back(root->val);
    
    if(!root->left && !root->right && targetSum == root->val){
        ans.push_back(path);
    }

    helper(root->left, targetSum - root->val, path);
    helper(root->right, targetSum - root->val, path);
    
    path.pop_back();
}

vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
    vector<int> path;
    helper(root, targetSum, path);
    return ans;
}

