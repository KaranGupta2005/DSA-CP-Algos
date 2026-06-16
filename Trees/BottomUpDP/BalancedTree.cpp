#include <bits/stdc++.h>
using namespace std;

/*
Balanced Binary Tree
- When for all the nodes : | leftHeight - rightHeight | <=1 : then the tree is balanced
- Here we need multiple information from the child:
    - The height 
    - Validity whether the subtree is balanced
- Avoid height(left) , height(right) for every node : O(n^2) complexity
- return -1 whenever tree becomes not balanced otherwise height
*/

int height(TreeNode* root){
    if(!root) return;

    int leftHeight=height(root->left);
    if(leftHeight == -1) return -1;

    int rightHeight=height(root->right);
    if(rightHeight == -1) return -1;

    if(abs(leftHeight - rightHeight) > 1) return -1;

    return max(leftHeight, rightHeight) + 1;
}

bool isBalanced(TreeNode* root){
    return height(root)!=-1;
}

