#include <bits/stdc++.h>
using namespace std;

/*
Duplicate Subtree in Binary Tree
- We will serialize all the subtrees , assign them a unique ID and store them in a map <string , int>
- Instead of storing long strings , we represent every subtree by an ID
- We will also maintain the count of the ID by using a hashmap <int , int> : ID->freq
- When a particular ID's frequency becomes 2, we will return true

There is an alternate approach
- We will just store the frquency of the serialized string in a hashmap
- When a particular serialized string's frequency becomes 2, we will return true
- But here the time complexity can reach O(n^2) in worst case because string comparison can take O(n) time
*/

// approach 1
unordered_map<string,int> idMap; // (val,leftID,rightID) -> ID
unordered_map<int,int> count; // ID -> count
vector<TreeNode*> result;
int nextID=1;

int dfs(TreeNode* node){
    if(!node) return 0; // 0 represents NULL

    int left=dfs(node->left);
    int right=dfs(node->right);
    
    string key= to_string(node->val)+","+to_string(left)+","+to_string(right);

    if(!idMap.count(key)){
        idMap[key]=nextID++;
    }
    
    int id=idMap[key];
    count[id]++;
    
    if(count[id]==2){
        result.push_back(node);
    }
    
    return id;
}

// Time Complexity: O(n) - Each node is visited once and string operations are O(1) due to fixed size
// Space Complexity: O(n) - For the hash maps and recursion stack

// approach 2
unordered_map<string,int> serialCount;
vector<TreeNode*> res;
string dfs2(TreeNode* node){
    if(!node) return "#";

    string left=dfs2(node->left);
    string right=dfs2(node->right);
    
    string key=to_string(node->val)+","+left+","+right;
    serialCount[key]++;

    if(serialCount[key]==2){
        res.push_back(node);
    }
    
    return key;
}

// Time Complexity : O(n) for dfs but string operations may take O(n) in worst case
// Space Complexity : O(n)

vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
    dfs(root);
    return result;
}
