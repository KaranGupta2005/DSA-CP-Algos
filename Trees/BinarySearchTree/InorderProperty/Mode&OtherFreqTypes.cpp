#include <bits/stdc++.h>
using namespace std;

/*
Mode in a BST:
- If the BST contains duplicates , same elements come consecutively
- Whenever duplicates , frequency types ques arises: think that the inorder of BST is sorted
- If don't need unordered_map : the problem reduces to previous pointer , current streak , max streak
*/

int count=0 , maxCount=0;
vector<int> ans;
TreeNode* prev=NULL;

void inorder(TreeNode* root){
    if(!root) return;

    inorder(root->left);

    if(prev && prev->val == root->val){
        count++;
    }else{
        count=1;
    }

    if(count>maxCount){
        maxCount=count;
        ans.clear();
        ans.push_back(root->val);
    }
    else if(count==maxCount){
        ans.push_back(root->val);
    }
    
    prev=root;
    
    inorder(root->right);
}

vector<int> findMode(TreeNode* root) {
    inorder(root);
    return ans;
}
