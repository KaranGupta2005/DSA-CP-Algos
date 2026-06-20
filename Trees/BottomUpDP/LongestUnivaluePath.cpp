#include <bits/stdc++.h>
using namespace std;

/*
Longest Univalue Path
- Longest path that has the nodes with same values
- Path can start and end at any node , but will be connected
- Each node returns to its parent the longest same-value chain starting from that node going downward to one side (one arm contribution)
    : max(leftArm , rightArm) (if height measured by edges otherwise add +1)
- But here is a twist : the chain can only be extended : if child->val == root->val
    : leftPath= left+1
    : rightPath= right+1
    : Local Contribution = leftPath + rightPath
*/

int ans=INT_MIN;

int helper(TreeNode* node){

    if(!node) return 0;

    int left=helper(node->left);
    int right=helper(node->right);

    int leftPath=0 , rightPath=0;

    if(node->left && node->left->val == node->val) leftPath=left+1;
    if(node->right && node->right->val == node->val) rightPath=right+1;

    ans=max(ans,leftPath+rightPath);

    return max(leftPath,rightPath);
}

int longestUnivaluePath(TreeNode* root) {
    if(!root) return 0;
    helper(root);
    return ans;
}
