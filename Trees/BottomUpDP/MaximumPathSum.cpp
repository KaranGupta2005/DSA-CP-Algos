#include <bits/stdc++.h>
using namespace std;

/*
Maximum Path Sum
- Path can be between any two nodes : can start and end anywhere , but will be connected
- A node returns the max path sum starting from that node to one side (one arm contribution)
    : node->val + max(left, right)
- Answer through node : The local best path going through this node
    : node->val + left + right
    : used to update the global maximum
- Negative Path Pruning : We will avoid negative contributions by taking max with 0
*/

int maxPath=INT_MIN;

int helper(TreeNode* node){

    if(!node) return 0;

    int left=max(0,helper(node->left));
    int right=max(0,helper(node->right));

    int throughNode=left+right+node->val;

    maxPath=max(maxPath,throughNode);

    return node->val+max(left,right);
}

int maxPathSum(TreeNode* root) {
    if(!root) return 0;
    helper(root);
    return maxPath;
}
