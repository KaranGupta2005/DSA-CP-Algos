#include <bits/stdc++.h>
using namespace std;

/*
Top View
- exactly the same : only first node of each column
- Data Structures :
    - Map : map<int , int> : {column -> value}
    - Queue : {TreeNode* , int} : {node , column}
*/

vector<int> topView(TreeNode* root){
    vector<int> ans;
    if(!root) return ans;

    map<int , int> mp;
    queue<pair<TreeNode* , int>> q;
    q.push({root,0});

    while(!q.empty()){
        auto [node,col]=q.front();
        q.pop();

        if(mp.find(col)==mp.end()){
            mp[col]=node->val;
        }

        if(node->left) q.push({node->left , col-1});
        if(node->right) q.push({node->right , col+1});
    }

    for(auto &it:mp){
        ans.push_back(it.second);
    }
    
    return ans;
}
