#include <bits/stdc++.h>
using namespace std;

/*
Delete A Node In BST
- when node->val == key , three cases can arise:
- 1. Node to be deleted is leaf node
    - delete node
    - return NULL
- 2. Node to be deleted has one child
    - delete node
    - return child
- 3. Node to be deleted has two children
    - find inorder successor : The smallest value in the right subtree
    - replace node with inorder successor
    - delete inorder successor
*/

TreeNode* deleteNode(TreeNode* root , int key){

    if(!root) return NULL;

    if(root->val > key){
        root->left=return(root->left , key);
    }
    else if(root->val < key){
        root->right=return(root->right , key);
    }
    else{

        if(!root->left && !root->right){
            delete root;
            return NULL;
        }
        if(!root->left || !root->right){
            TreeNode* child = (root->left)? root->left : root->right;
            delete root;
            return child;
        }
        
        TreeNode* succ=root->right;
        while(succ->left){
            succ=succ->left;
        }

        root->val=succ->val;
        root->right=deleteNode(root->right , succ->val);
    
        return root;
    }
}