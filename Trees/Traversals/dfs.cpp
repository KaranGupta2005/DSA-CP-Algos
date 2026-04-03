#include <bits/stdc++.h>
using namespace std;

/*
A tree is a hierchial , recursive data structure
- tree= value+left subtree+right subtree
- a tree is not always symmetric/balanced , so solve for left and right both
- every tree problem = traversal + some logic
*/

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x){
        this->val=x;
        this->left=nullptr;
        this->right=nullptr;
    }
};

//DFS(Depth First Search)-> go as deep as possible then come back

// root->left->right
// when you want to process the nodes before visiting their children
// Top-Down approach
void preorder(TreeNode* root){
    if(!root) return;

    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

// left->root->right
// in BST: inorder traversal gives sorted order
void inorder(TreeNode* root){
    if(!root) return;

    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

// left->right->root
// when we have to process children before parent (e.g., deleting a tree)
// Bottom-Up approach
void postorder(TreeNode* root){
    if(!root) return;

    postorder(root->left);
    postorder(root->right);
    cout<<(root->val)<<" ";
}

// Time Complexity: O(n) for all traversals
// Space Complexity: O(h) where h is height of tree (recursion stack)
// In worst case (skewed tree), space complexity can be O(n)