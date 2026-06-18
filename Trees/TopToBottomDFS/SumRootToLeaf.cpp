#include <bits/stdc++.h>
using namespace std;

/*
Sum Root To Leaf Numbers

- the path 1->4->5->7 : represents a number 1457
- return the sum of all the numbers formed by the paths from root to leaf
- if the decimal numbers are there :
    newNum=(oldNum)*10+(node->val)
- if the numbers are binary :
    newNum=(oldNum)<<1|(node->val)
*/

int helper(TreeNode* node , int curr){
    if(!node) return 0;

    curr=(curr*10)+node->val;

    if(!node->left && !node->right){
        return curr;
    }

    return helper(node->left , curr) + helper(node->right , curr);
}
int sumNumbers(TreeNode* root) {
    if(!root) return 0;
    return helper(root,0);
}