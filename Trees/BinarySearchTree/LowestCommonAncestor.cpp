#include <bits/stdc++.h>
using namespace std;

/*
LCA in BST

- Suppose there are two nodes p , q
- if p->val && q->val < root->val then LCA lies in left subtree
- if p->val && q->val > root->val then LCA lies in right subtree
Otherwise:
- if p->val && q->val == root->val then LCA is root
- if p->val < root->val && q->val > root->val then LCA is root and vice versa
*/

TreeNode* lowestCommonAncestor(TreeNode* root , TreeNode* p , TreeNode* q){

    while(root){
        if(p->val < root->val && q->val < root->val){
            root = root->left;
        }
        else if(p->val > root->val && q->val > root->val){
            root = root->right;
        }
        else{
            return root;
        }
    }
    return NULL;
}