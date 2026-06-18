#include <bits/stdc++.h>
using namespace std;

vector<double> averageOfLevels(TreeNode* root)
{
    vector<double> ans;

    queue<TreeNode*> q;

    q.push(root);

    while(!q.empty())
    {
        int sz=q.size();

        long long sum=0;

        for(int i=0;i<sz;i++)
        {
            auto node=q.front();
            q.pop();

            sum+=node->val;

            if(node->left)
                q.push(node->left);

            if(node->right)
                q.push(node->right);
        }

        ans.push_back(
            (double)sum/sz
        );
    }

    return ans;
}

// similiarly : maximum of each level