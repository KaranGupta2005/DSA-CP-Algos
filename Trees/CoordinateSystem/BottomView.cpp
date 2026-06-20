#include <bits/stdc++.h>
using namespace std;

/*
Bottom View of Binary Tree
- Exactly same as top view, just we store the last node of each column
- Instead of checking if column exists in map, we directly update it
    - mp[col]=node->val
*/

vector<int> bottomView(Node *root)
{
    vector<int> ans;

    if(!root)
        return ans;

    map<int,int> mp;

    queue<pair<Node*,int>> q;

    q.push({root,0});

    while(!q.empty())
    {
        auto [node,col]=q.front();
        q.pop();

        mp[col]=node->data;

        if(node->left)
            q.push({
                node->left,
                col-1
            });

        if(node->right)
            q.push({
                node->right,
                col+1
            });
    }

    for(auto &it:mp)
        ans.push_back(it.second);

    return ans;
}
