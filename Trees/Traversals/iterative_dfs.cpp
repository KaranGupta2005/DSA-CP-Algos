#include <bits/c++.h>
using namespace std;

/*
Iterative DFS
- in recursion , there is a hidden stack , but using a stack helps ou control that
- In stack-> we store those nodes waiting to be processed
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
/*
- Left Root Right
- go as left as possible till it is not possible
- then process the node
- then go to right
*/
vector<int>inorder(TreeNode* root){
    vector<int> result;
    if(!root) return result;

    stack<TreeNode*> st;
    TreeNode* curr=root;

    while(curr || !st.empty()){
        while(curr){
            st.push(curr);
            curr=curr->left;
        }

        TreeNode* node=st.top();
        st.pop();
        result.push_back(node->val);

        curr=curr->right;
    }

    return result;
}

/*
- Root Left Right
- Process the node immediately
- then go to left
- then go to right

- firstly push right -> then left into the stack coz stack is a LIFO data structure 
*/
vector<int> preorder(TreeNode* root){
    vector<int> result;
    if(!root) return result;

    stack<TreeNode*> st;
    st.push(root);

    while(!st.empty()){
        TreeNode* node=st.top();
        st.pop();
        result.push_back(node->val);

        if(node->right) st.push(node->right);
        if(node->left) st.push(node->left);
    }
    
    return result;
}   

/*
- Left Right Root
- we will be using two stacks
- first stack is used to process the nodes ( reverse preorder logic)
- second stack is used to store the nodes in reverse order
*/
vector<int> postorder(TreeNode* root){
    vector<int> result;
    if(!root) return result;

    stack<TreeNode*> st1,st2;
    st1.push(root);

    while(!st1.empty()){
        TreeNode* node=st1.top();
        st1.pop();
        st2.push(node);
        
        if(node->left) st1.push(node->left);
        if(node->right) st1.push(node->right);
    }
    
    while(!st2.empty()){
        result.push_back(st2.top()->val);
        st2.pop();
    }
    
    return result;
}

/*
- Uses a single stack only
- but have to keep the track of lastvisited node
*/
vector<int> postorder2(TreeNode* root){
    vector<int> result;
    if(!root) return result;

    TreeNode* lastVisited=nullptr;
    stack<TreeNode*> st;

    while(curr || !st.empty()){
        while(curr){
            st.push(curr);
            curr=curr->left;
        }

        TreeNode* node=st.top();
        if(node->right && lastVisited!=node->right){
            curr=node->right;
        }
        else{
            // process the node
            result.push_back(node->val);
            lastVisited=node;
            st.pop();
        }
    }
    
    return result;
}
// Time Complexity: O(n)
// Space Complexity: O(h) where h is the height of the tree
