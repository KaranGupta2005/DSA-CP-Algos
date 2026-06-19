#include <bits/stdc++.h>
using namespace std;

/*
Kth Smallest Element in a BST
- Inorder traversal of BST gives sorted order
- We can create inorder array and return kth element
- But we can optimize by stopping when we find kth element : by keeping count during the inorder traversal
*/

//BruteForce
void inorder(TreeNode* root , vector<int>& nums){
    if(!root) return;
    inorder(root->left , nums);
    nums.push_back(root->val);
    inorder(root->right , nums);
}

int kthSmallest(TreeNode* root , int k){
    vector<int> nums;
    inorder(root , nums);

    return nums[k-1];
}

//Optimized

int count=0;
int answer=0;

void inorder(TreeNode* root , int k){

    if(!root) return;

    inorder(root->left , k);

    count++;
    if(count==k){
        answer= root->val;
        return;
    }

    inorder(root->right , k);
}

int kthSmallest(TreeNode* root , int k){
    inorder(root , k);
    return answer;
}
