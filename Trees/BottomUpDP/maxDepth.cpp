#include <bits/stdcpp.h>
using namespace std;

// Maximum Depth= maximum number of nodes from the root to any leaf
/*
Height of a node
- check left subtree
- check right subtree
- take maximum value + 1 (for current node)

- we have to process children info first
- so it's a postorder traversal
*/

int maxDepth(TreeNode* root){
    if(!root) return 0;

    int leftHeight=maxDepth(root->left);
    int rightHeight=maxDepth(root->right);

    return max(leftHeight,rightHeight) + 1;
}

/*
Same Tree
- check if two trees are identical
- check if values of nodes are equal
- check if left subtrees are equal
- check if right subtrees are equal
*/
bool sameTree(TreeNode* p , TreeNode* q){
    if(!p && !q) return true;
    if(!p || !q) return false;
    if(p->val != q->val) return false;

    return sameTree(p->left , q->left) && sameTree(p->right , q->right);
}