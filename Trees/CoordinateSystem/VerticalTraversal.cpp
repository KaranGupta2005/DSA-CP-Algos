#include <bits/stdc++.h>
using namespace std;

/*
Vertical Order Traversal:
- Vertical , top , bottom view these belong to the same family , we move horizontally here 
- The difference lies how we process nodes at the same column
    - root : {0 , 0}
    - moving to left child : { row+1 , col-1 }
    - moving to right child : { row+1 , col+1 }
          1(0,0)

       /          \
   2(1,-1)      3(1,+1)

   /    \       /     \
4(2,-2) 5(2,0) 6(2,0) 7(2,2)
- In vertical order : grouped by column
- Will Use BFS : it ensurres higher levels are processed first
- Data Structures:
    - Map : map<int , map<int , multiset<int>>> : {column -> {row -> values}}
    - Queue : {TreeNode* , {row , col}}
*/

vector<vector<int>> verticalTraversal(TreeNode* root) {
    vector<vector<int>> ans;
    if(!root) return ans;

    map<int,map<int , multiset<int>>> mp;

    queue<pair<TreeNode*,pair<int,int>>> q;
    q.push({root , {0,0}});

    while(!q.empty()){
        auto top=q.front();
        q.pop();

        TreeNode* node=top.first;
        auto [row,col] = top.second;

        mp[col][row].insert(node->val);

        if(node->left){
            q.push({node->left , {row+1 , col-1}});
        }

        if(node->right){
            q.push({node->right , {row+1 , col+1}});
        }
    }

    for(auto &colPairs:mp){
        vector<int> v;

        for(auto &rowPairs:colPairs.second){
            v.insert(v.end(),rowPairs.second.begin(),rowPairs.second.end());
        }

        ans.push_back(v);
    }
        
    return ans;
}