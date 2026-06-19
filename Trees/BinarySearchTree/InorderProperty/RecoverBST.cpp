#include <bits/stdc++.h>
using namespace std;

/*
Recover BST
- In a BST , two nodes were swapped , we need to recover the BST
- In order to find the 2 nodes to be swapped , we will be using the inorder property
- if(prev && prev->val > root->val) : then violation exists
- There can be 2 cases : adjacent and non adjacent swap

eg:      1 5 3 4 2 6  (inorder)
Violations : 5 > 3 && 4 > 2
1.  first = 5
    second = 3
2.  second = 2

at last: swap(first, second)

eg.     1 3 2 4 5
Violations : 3 > 2
1.  first = 3
    second = 2

at last: swap(first, second)
*/

TreeNode* first=NULL;
TreeNode* second=NULL;
TreeNode* prev=NULL;

void inorder(TreeNode* root) {
    
    if(!root) return;

    inorder(root->left);

    if(prev && prev->val > root->val){
        if(!first){
            first=prev;
            second=root;
        }else{
            second=root;
        }
    }

    prev=root;

    inorder(root->right);
}

void recoverTree(TreeNode* root) {
    inorder(root);
    swap(first->val, second->val);
}