#include <bits/stdc++.h>
using namespace std;

/*
Valid BST
- Here we pass the constraints downward
- each node should know the max and min allowed values
- Root -> Left : for left allowed values are (-infinity, root->val)
- Root -> Right : for right allowed values are (root->val, infinity)

- The most bruteforce approach is to find inorder and check if it is sorted
*/

bool validate(TreeNode* root , long long low , long long high){
    if(!root) return true;

    if(root->val <= low || root->val >= high) return false;

    return validate(root->left , low , root->val) && validate(root->right , root->val , high);
}

bool isValidateBST(TreeNode* root){
    return validate(root , LLONG_MIN , LLONG_MAX);
}