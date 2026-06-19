#include <bits/stdc++.h>
using namespace std;

/*
Binary Search Tree
- a special Binary tree where for each node -> 
    - all the nodes in the left subtree have values less than the node value
    - all the nodes in the right subtree have values greater than the node value
- Special Property that the inorder of a Binary Search Tree is always sorted
*/

TreeNode* searchBST(TreeNode* root, int val) {
    
    if(!root) return NULL;

    if(root->val == val) return root;

    if(root->val > val) return searchBST(root->left , val);
    else return searchBST(root->right , val);
    
}
