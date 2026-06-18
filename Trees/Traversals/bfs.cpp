#include <bits/stdc++.h>
using namespace std;

/*
BFS (Breadth First Search) -> Level Order Traversal
*/

vector<vector<int>> levelOrder(TreeNode* root){
    vector<vector<int>> result;
    if(!root) return result;

    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()){
        int size=q.size(); // number of nodes in current level
        vector<int> level;

        for(int i=0;i<size;i++){
            auto* top=q.front();
            q.pop();
            level.push_back(top->val);

            if(top->left) q.push(top->left);
            if(top->right) q.push(top->right);
        }
        
        result.push_back(level);
    }
    
    return result;
}
// Time Complexity: O(n)
// Space Complexity: O(w) where w is the maximum width of the tree
// BFS used to find the shortest path in unweighted graphs
