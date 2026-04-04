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