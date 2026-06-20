#include <bits/stdc++.h>
using namespace std;

/*
Trimming a BST
- It is not equivalent to deletion of any nodes , it's simply choose the valid nodes that belong to [low,high]
- When root->val < low , the entire left subtree is invalid : ignore and move right
    - return trimBST(root->left , low , high)
- When root->val > high , the entire right subtree is invalid : ignore and move left
    - return trimBST(root->right , low , high)
- When root->val is in range [low,high] , keep the node and recursively trim both subtrees
    - root->left = trimBST(root->left , low , high)
    - root->right = trimBST(root->right , low , high)
*/

TreeNode* trimBST(TreeNode* root , int low , int high){
    if(!root) return NULL;

    if(root->val < low){
        return trimBST(root->right , low , high);
    }

    if(root->val > high){
        return trimBST(root->left , low , high);
    }
    
    root->left = trimBST(root->left , low , high);
    root->right = trimBST(root->right , low , high);
    
    return root;
}