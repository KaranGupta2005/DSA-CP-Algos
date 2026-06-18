#include <bits/stdc++.h>
using namespace std;

// return all the paths from root->leaf that are possible
// Here the parent sends the current path to the children

vector<string> ans;

void helper(TreeNode* node , string s){
    if(!node) return;

    s+=to_string(node->val);

    if(!node->left && !node->right){
        ans.push_back(s);
        return;
    }

    s+="->";

    helper(node->left , s);
    helper(node->right , s);

}
vector<string> binaryTreePaths(TreeNode* root) {

    helper(root , "");
    return ans;
}
