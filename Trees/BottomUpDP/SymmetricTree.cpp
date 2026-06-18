#include <bits/stdc++.h>
using namespace std;

/*
Symmetric Tree / Mirror Recursion
- Two trees are mirror images if:
  - Their root values are equal
  - left->val == right->val
  - left->left == right->right
  - left->right == right->left
*/

bool mirror(TreeNode* left , TreeNode* right){
    if(!left && !right) return true;
    if(!left || !right) return false;

    if(left->val != right->val) return false;

    return mirror(left->left, right->right) && mirror(left->right, right->left);
}

bool isSymmetric(TreeNode* root) {
    if(!root) return true;
    return mirror(root->left, root->right);
}
