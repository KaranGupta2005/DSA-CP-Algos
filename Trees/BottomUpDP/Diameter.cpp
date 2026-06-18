#include <bits/stdc++.h>
using namespace std;

/*
Diameter of Binary Tree
- The longest distance b/w any two nodes in the tree
- The path may or may not pass through the root

- Every node :
    - seek the leftHeight and rightHeight from its children
    - Update the global diameter
    - Pass on the height to its parent

- Time Complexity : O(n) : Every node is visited once
- Space Complexity : O(h) where h is the height of the tree
*/

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int diameter=0;

int helper(TreeNode* node){
    if(!node) return 0;

    int leftHeight=helper(node->left);
    int rightHeight=helper(node->right);
    
    diameter=max(diameter,leftHeight+rightHeight);
    
    return max(leftHeight,rightHeight)+1;
}

int diameterOfBinaryTree(TreeNode* root) {
    helper(root);
    return diameter;
}
