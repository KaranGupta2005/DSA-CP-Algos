#include <bits/stdc++.h>
using namespace std;

/*
Right Side View
- The answer vector should include the rightmost node of each level
- BFS with level tracking
- DFS : Visit right child first, then left child
*/

vector<int> rightSideView(TreeNode* root){

    vector<int> ans;
    if(!root) return ans;

    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()){
        int n=q.size();

        for(int i=0 ; i<n ; i++){
            auto node=q.front();
            q.pop();

            if(i==n-1) ans.push_back(node->val);
            
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
    }
    
    return ans;
}


vector<int> res;
void helper(TreeNode* root , int depth){
    
    if(!root) return;

    if(depth == res.size()){
        res.push_back(root->val);
    }

    helper(root->right , depth+1);
    helper(root->left , depth+1);
}

vector<int> rightSideView(TreeNode* root){
    helper(root, 0);
    return res;
}
