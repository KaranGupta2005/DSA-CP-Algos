#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> zigzagLevelOrder(TreeNode* root){
    vector<vector<int>> result;
    if(!root) return result;

    queue<TreeNode*> q;
    q.push(root);

    bool leftToRight = true;

    while(!q.empty()){
        int size=q.size(); // number of nodes in current level
        vector<int> level(size,0);

        for(int i=0;i<size;i++){
            auto* top=q.front();
            q.pop();

            int idx=(leftToRight) ? i : size-1-i;
            level[idx] = top->val;

            if(top->left) q.push(top->left);
            if(top->right) q.push(top->right);  
        }
        
        
        
        result.push_back(level);
        leftToRight = !leftToRight;
    }
    
    return result;
}
// Level by level traversal with alternating direction
// firstly left->right then right->left
// instead of reversing after each level , we place the elements correctly