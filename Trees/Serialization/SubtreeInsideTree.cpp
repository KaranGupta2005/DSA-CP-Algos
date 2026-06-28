#include <bits/stdc++.h>
using namespace std;

/*
Euler Serialization:
- One way to approach this problem is to apply euler tour for both the main tree and the subtree.
- Then check if the subtree's euler tour is a substring of the main tree's euler tour.

- So we apply Euler serialization to represent each in terms of string and then pattern matching through KMP or Rabin Karp algorithm

- We also store markers for null nodes to ensure unique representation
    1         1,2,#,#,#            
   /
  2
      1       1,#,2,#,#    
     \
      2
    
*/

void dfs(TreeNode* root , string& euler){
    if(!root){
        euler+=(",#");
        return;
    }

    euler+=","+(to_string(root->val));

    dfs(root->left , euler);
    dfs(root->right , euler);
}
bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    if(!root && !subRoot) return true;
    if(!root || !subRoot) return false;

    string tree , subTree;
    dfs(root,tree);
    dfs(subRoot , subTree);

    int n=tree.size();
    int m=subTree.size();

    if(m>n) return false;

    return tree.find(subTree)!=string::npos;
}