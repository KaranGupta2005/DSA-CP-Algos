#include <bits/stdc++.h>
using namespace std;

/*
Morris Inorder Traversal
- This is space efficient
- In recursive or traversals with stack , SC=O(h) where h is the height of the tree
- Morris Traversal uses O(1) space

Threading
- The right node of the rightmost node of the left subtree points->current node

For each node

- If left child not exist:
Will process it and move to the right

- If left child exists:
Will find the predecessor (rightmost node of the left subtree)
- if predecessor.right==NULL:
  - Create a thread (predecessor.right = current node)
  - Move to the left child

- if predecessor.right==current node:
  - Remove the thread (predecessor.right = NULL)
  - Process the current node
  - Move to the right child
*/

vector<int> morrisInorder(TreeNode* root){
    vector<int> result;
    if(!root) return result;

    TreeNode* curr=root;

    while(curr){
        if(!curr->left){
            result.push_back(curr->val);
            curr=curr->right;
        }
        else{
            TreeNode* prev=curr->left;

            while(prev->right && prev->right!=curr){
                prev=prev->right;
            }

            if(!prev->right){
                // threading
                prev->right=curr;
                // move left
                curr=curr->left;
            }else{
                //remove thread
                prev->right=nullptr;
                result.push_back(curr->val);
                // move right
                curr=curr->right;
            }
        }
    }
    return result;
}

// Morris preorder Traversal
// process the curr before moving left
vector<int> morrisPreorder(TreeNode* root){
    vector<int> result;
    if(!root) return result;

    TreeNode* curr=root;

    while(curr){
        if(!curr->left){
            result.push_back(curr->val);
            curr=curr->right;
        }
        else{
            TreeNode* prev=curr->left;

            while(prev->right && prev->right!=curr){
                prev=prev->right;
            }

            if(!prev->right){
                prev->right=curr;
                result.push_back(curr->val);
                curr=curr->left;
            }
            else{
                prev->right=nullptr;
                curr=curr->right;
            }
        }
    }
    return result;
}

// Time Complexity: O(3N) = O(N)
// Space Complexity: O(1)