#include <bits/stdc++.h>
using namespace std;

/*
- In binary trees , there is no need for prefix / suffix array in dfs2
- for a node (root) : root->left and root->right are its child and root->right is sibling for root->left and vice versa
- answer[node]=max(down[node], up[node])
*/

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

unordered_map<int, int> down;
unordered_map<int, int> up;

int dfs1(TreeNode* root){
    if(!root) return -1;

    int left=dfs1(root->left)+1;
    int right=dfs1(root->right)+1;

    down[root->val]=max(left,right); // longest distance inside the subtree

    return down[root->val];
}

void dfs2(TreeNode* root){
    if(!root) return;

    if(root->left){
        int sibling=(root->right)? down[root->right->val]+1:0;
        up[root->left->val]=max(up[root->val]+1 , sibling+1); // root -> root->right wali edge
                    // root->root->left wali edge  
        
        dfs2(root->left);
    }

    if(root->right){
        int sibling=(root->left)? down[root->left->val]+1:0;
        up[root->right->val]=max(up[root->val]+1 , sibling+1); // root -> root->left wali edge
                    // root->root->right wali edge  
        
        dfs2(root->right);
    }
}

vector<int> solve(TreeNode* root){
    dfs1(root);
    dfs2(root);
    
    vector<int> result;
    for(auto& pair : down){
        result.push_back(max(pair.second, up[pair.first]));
    }
    
    return result;
}
