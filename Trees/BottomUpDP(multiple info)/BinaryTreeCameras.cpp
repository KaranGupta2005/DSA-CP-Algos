#include <bits/stdc++.h>
using namespace std;

/*
Binary Tree Cameras
- One camera can monitor : itself ( current node ) , parent , left child && rigth child
- We have to return minimum number of cameras to monitor all nodes
- At leaf nodes : There is no need to install any camera , its parent would oversee ( cheaper )
                : Child of leaf : Null : if null returns not covered -> root must install camera ( unnecessary )
                                       : Hence null returns covered
- For a node :
    : if any of its child is not covered : you have to install the camera
    : if any of its child has camera : then that node already covered
    : if both the child covered but has no camera : then that node not covered : its parent would oversee

- Three states are :
    0: Has camera
    1: Covered
    2: Not covered
*/

    int cameras=0;

    int dfs(TreeNode* root){
        if(!root) return 1;

        auto left=dfs(root->left);
        auto right=dfs(root->right);

        if(left==2 || right==0){
            cameras++;
            return 0;
        }

        if(left==0 || right==0){
            return 1;
        }

        return 2;
    }
    int minCameraCover(TreeNode* root) {
        if(!root) return 0;

        if(dfs(root)==2) cameras++;
        return cameras;
    }