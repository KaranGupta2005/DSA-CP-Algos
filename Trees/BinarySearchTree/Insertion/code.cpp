#include <bits/stdc++.h>
using namespace std;

/*
Insertion Into BST
- when NULL will be reached , insert there
- we are returning the modified subtree node
*/

TreeNode* insertIntoBST(TreeNode* root, int val) {
    
    if(!root) return new TreeNode(val);
    
    if(val < root->val) root->left = insertIntoBST(root->left, val);
    else root->right = insertIntoBST(root->right, val);
    
    return root;
}