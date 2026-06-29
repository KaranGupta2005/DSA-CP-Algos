#include <bits/stdc++.h>
using namespace std;

/*
All Nodes Distance K in Binary Tree

Method 1
- Parent Map + DFS ( Will do dfs 2 times , one to build the parent map and another to find nodes at distance k)
- We can traverse down a binary tree , as each node has only child pointer , but here we have to go up as well
- So we should build a unidirectional graph by storing each node's parent
- After this start DFS from the target and traverse in all 3 directions (parent, left child, right child) and collect nodes at distance k
- Just need to make sure we don't go back to the node we came from ( prev )
*/
unordered_map<TreeNode*, TreeNode*> parent;
vector<int> ans;

void buildParent(TreeNode* root , TreeNode* par){
    if(!root) return;

    parent[root]=par;
    buildParent(root->left , root);
    buildParent(root->right , root);
}

void dfs(TreeNode* root , TreeNode* prev , int dist , int k){
    if(!root) return;

    if(dist == k){
        ans.push_back(root->val);
        return;
    }

    if(root->left != prev) dfs(root->left , root , dist+1 , k);
    if(root->right != prev) dfs(root->right , root , dist+1 , k);
    if(parent[root] != prev) dfs(parent[root] , root , dist+1 , k);

}

vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    buildParent(root , NULL);
    dfs(target , NULL , 0 , k);
    return ans;
}

