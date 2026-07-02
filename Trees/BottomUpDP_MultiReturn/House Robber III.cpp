#include <bits/stdc++.h>
using namespace std;

/*
House Robber III
- In tree version : you cannot rob parent and child together
- Will recursively check for the left & right subtree
- At each node two cases arises:
    - Rob the node : Cannot rob children : node->val + left.skip + right.skip
    - Skip the node : Can rob the children : max(left.skip , left.rob) + max(right.skip , right.rob)
- Each node should return {rob (maximum money if we rob the node) , skip(maximum value if we skip the node)}
*/

pair<int,int> dfs(TreeNode* root){
    if(!root) return {0,0};

    auto left=dfs(root->left);
    auto right=dfs(root->right);

    int rob= root->val + left.second + right.second;
    int skip= max(left.first , left.second) + max(right.first , right.second);

    return {rob , skip};
}

int rob(TreeNode* root){
    if(!root) return 0;

    auto ans=dfs(root);

    return max(ans.first , ans.second);
}