#include <bits/stdc++.h>
using namespace std;

/*
Largets BST in a Binary Tree
- At every node , we must validate whether it is a valid BST or not 
- Each node must return 4 values {bool validBST , int countSize , int minVal , int maxVal}
- At each node:
    : if(left.isBST && right.isBST && left.maxVal < root->val && right.minValue > root->val)
        : size= left.size + right.size + 1
*/

struct Info{
    bool isBST;
    int size;
    int minVal;
    int maxVal;
};

int ans=0;

Info dfs(TreeNode* root){
    if(!root){
        return { true , 0 , INT_MAX , INT_MIN};
    }

    Info left=dfs(root->left);
    Info right=dfs(root->right);

    if(left.isBST && right.isBST && left.maxVal < root->data && right.minVal > root->data ){
        int currSize=left.size + right.size + 1;

        ans=max(ans , currSize);

        return {
            true , currSize ,
            min(left.minVal , root->val),
            max(right.maxVal , root->val)
        };
    }

    return { false , 0 , INT_MAX , INT_MIN };
} 

int largestBST(TreeNode* root){
    if(!root) return 0;

    dfs(root);
    return ans;
}



