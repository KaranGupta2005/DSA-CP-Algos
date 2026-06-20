#include <bits/stdc++.h>
using namespace std;

/*
Boundary Traversal
- It composes of 4 parts:
    - include root
    - include left boundary (excluding leaf)
    - include all leaf nodes (left to right)
    - include right boundary (excluding leaf, in reverse)
- Time Complexity : O(N) : every node visited once
- Space Complexity : O(H) : recursion stack space
*/

bool isLeaf(TreeNode* root){
    return (root && !root->left && !root->right);
}

void addLeftBoundary(TreeNode* root , vector<int>& ans){
    if(!root || isLeaf(root)) return;

    TreeNode* curr=root->left;
    while(curr){
        if(!isLeaf(curr)) ans.push_back(curr->val);

        if(curr->left) curr=curr->left;
        else curr=curr->right;
    }
}

void addLeaves(TreeNode* root , vector<int>& ans){
    
    if(!root) return;

    if(isLeaf(root)) ans.push_back(root->val);
    
    addLeaves(root->left, ans);
    addLeaves(root->right, ans);
}

void addRightBoundary(TreeNode* root , vector<int>& ans){
    
    if(!root || isLeaf(root)) return;

    stack<int> st;
    TreeNode* curr=root->right;

    while(curr){
        if(!isLeaf(curr)) st.push(curr->val);

        if(curr->right){
            curr=curr->right;
        }else{
            curr=curr->left;
        }
    }

    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
}

vector<int> boundaryTraversal(TreeNode* root){
    vector<int> ans;
    
    if(!root) return ans;
    
    if(!isLeaf(root)) ans.push_back(root->val);
    
    addLeftBoundary(root, ans);
    addLeaves(root, ans);
    addRightBoundary(root, ans);
    
    return ans;
}
