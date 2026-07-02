#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) {
        this->val = x;
        this->left = this->right = NULL;
    }
};

const int LOG = 20;
unordered_map<TreeNode*,vector<TreeNode*>> up;
unord ered_map<TreeNode*,int> depth;

void dfs(TreeNode* node , TreeNode* parent){
    if(!node) return;

    up[node].resize(LOG);
    up[node][0]=parent;

    for(int j=1;j<LOG;j++){
        if(up[node][j-1]){
            up[node][j] = up[up[node][j-1]][j-1];
        }
        else{
            up[node][j] = NULL;
        }
    }

    if(node->left){
        depth[node->left] = depth[node] + 1;
        dfs(node->left, node);
    }
    
    if(node->right){
        depth[node->right] = depth[node] + 1;
        dfs(node->right, node);
    }
}

TreeNode* liftNode(TreeNode* node, int k) {
    for (int j = 0; j < LOG; j++) {
        if (k & (1 << j)) {
            node = up[node][j];
            if (!node) break;
        }
    }
    return node;
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

    depth[root] = 0;
    // dfs to build the depth and up array
    dfs(root, NULL);

    TreeNode* u = p;
    TreeNode* v = q;

    // Step 1: bring to same depth
    if (depth[u] < depth[v]) swap(u, v);
    u = liftNode(u, depth[u] - depth[v]);

    // Step 2: if same
    if (u == v) return u;

    // Step 3: lift both
    for (int j = LOG - 1; j >= 0; j--) {
        if (up[u][j] && up[u][j] != up[v][j]) {
            u = up[u][j];
            v = up[v][j];
        }
    }

    // Step 4: return parent
    return up[u][0];
}
