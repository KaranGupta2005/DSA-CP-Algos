#include <bits/stdc++.h>
using namespace std;

/*
LCA of a Binary Tree
- The earliest common ancestor of two nodes , where both path meets
- Bottom-Up approach : each node returns whether p found or whether q found
- when found p or q -> return node
- search both left and right side
- if both null -> return null
- if (left && right) : return root : LCA found
- if(left || right) : return left or right
*/

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    
    if(!root) return NULL;

    if(root==p || root==q) return root;

    TreeNode* left=lowestCommonAncestor(root->left, p, q);
    TreeNode* right=lowestCommonAncestor(root->right, p, q);

    if(left && right) return root;
    if(left || right) return left ? left : right;
    return NULL;
}

/*
Time Complexity: O(n)
Space Complexity: O(h) where h is the height of the tree

Distance b/w 2 nodes:
- distance(7,4)
- say LCA : 2
- distance(7,2) + distance(4,2) == ans
*/
