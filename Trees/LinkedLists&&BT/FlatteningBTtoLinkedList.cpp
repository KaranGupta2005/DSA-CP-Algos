#include <bits/stdc++.h>
using namespace std;

/*
Flattening a Binary Tree to Linked List
- The flattened tree is nothing but the preorder
- Each node has it's right node pointing to the next while the left node->null

Method 1:
- Do a preorder traversal and store the nodes in an array
- Then link each node to the next node in the array
- Time Complexity: O(n)
- Space Complexity: O(n)
*/

/*
Method 2: (Recursive Method)
- We will first flatten the left subtree , then the right subtree
- Store the current right subtree
- Then point the current node->right=node->left && node->left=nullptr
- Then find the rightmost node in the flattened left subtree
- attach the saved right subtree to it's right
*/
void flatten(TreeNode* root){
    (!root) return;

    flatten(root->left);
    flatten(root->right);

    TreeNode* temp=root->right;

    root->right=root->left;
    root->left=nullptr;

    TreeNode* curr=root;
    while(curr->right) curr=curr->right;
    
    curr->right=temp;
}
// Time Complexity: O(n*2) - O(n) for traversal and O(n) for finding rightmost node
// Space Complexity: O(n) - due to recursion stack

/*
Method 3: Reverse Preorder 
- Will follow this order : Right -> Left -> Root
*/

TreeNode* prev=NULL;

void flatten(TreeNode* root){
    if(!root) return;

    flatten(root->right);
    flatten(root->left);

    root->right=prev;
    root->left=nullptr;
    prev=root;
}

// Time Complexity: O(n)
// Space Complexity: O(n) - due to recursion stack

/*
Method 4: Morris Traversal
- Will use the concept of threaded binary tree
- If curr->left exists, find the rightmost node in the left subtree
- Make the rightmost node point to curr->right
- Then make curr->right = curr->left and curr->left = nullptr
- Move curr to curr->right (in the flattened tree)
*/
void flatten(TreeNode* root){
    if(!root) return;

    TreeNode* curr=root;
    while(curr){
        if(curr->left){
            TreeNode* prev=curr->left;

            while(prev->right) prev=prev->right;

            prev->right=curr->right;
            curr->right=curr->left;
            curr->left=nullptr;
        }
        curr=curr->right;
    }
}

