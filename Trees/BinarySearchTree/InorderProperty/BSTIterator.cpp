#include <bits/stdc++.h>
using namespace std;

/*
BST Iterator

Bruteforce:
- store the entire inorder traversal in an array
- maintain a pointer to track the current position
- Time: O(n) for initialization, O(1) for next() and hasNext()
- Space: O(n)
*/

class BSTIterator {
public:
    vector<int> arr;
    int idx;

    void inorder(TreeNode* root){
        if(!root) return;

        inorder(root->left);

        arr.push_back(root->val);

        inorder(root->right);
    }

    BSTIterator(TreeNode* root) {
        idx=0;
        inorder(root);
    }
    
    int next() {
        return arr[idx++];
    }
    
    bool hasNext() {
        return (idx<arr.size());
    }
};

/*
Lazy Traversal:
- using a stack to simulate the inorder traversal
- Inorder : left -> root -> right
- Move as left as possible until null is reached
- whenever you visit a node -> move to the right and push all its left children
    -   TreeNode* node = st.top();
        st.pop();
        pushLeft(node->right);
        return node->val; // stack.top() -> next element
- Time: O(h) for initialization, O(1) amortized for next() and hasNext()
- Space: O(h) where h is the height of the tree
*/

class BSTIterator {
public:
    stack<TreeNode*> st;
    
    void pushLeft(TreeNode* node){
        while(node){
            st.push(node);
            node=node->left;
        }
    }

    BSTIterator(TreeNode* root) {
        pushLeft(root);
    }
    
    int next() {
        TreeNode* top=st.top();
        st.pop();
        pushLeft(top->right);
        
        return top->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};