#include <bits/stdc++.h>
using namespace std;

/*
Euler Tour
- Used when Subtree Sum Queries , Subtree Update , Segment Trees on Trees , Fenwick Trees on trees , Max / Min in a Subtree , XOR in a subtree 
- If we do DFS , suppose there are N nodes and Q Queries , each time DFS takes O(n) and for Q queries : O(NQ) : Fails for large constraints

Intuition
                1
             /     \
            2       3
          /  \     / \
         4    5   6   7
- preOrder DFS : 1 2 4 5 3 6 7
- Now observe subtree of 2 ( 2 , 4 , 5) or subtree of 3 ( 3 , 6 , 7) appear as a contiguous block
- Also track the tIn and tOut for each Node
| Node | tin | tout |
| ---- | --- | ---- |
| 1    | 1   | 7    |
| 2    | 2   | 4    |
| 3    | 5   | 7    |
| 4    | 3   | 3    |
| 5    | 4   | 4    |
| 6    | 6   | 6    |
| 7    | 7   | 7    |
- Subtree of 2 : tin=2 to tout=4 : 2 , 4 , 5 (tin is called the Euler order)

Flatten tree :
             : Euler Order : 1 2 4 5 3 6 7
             : Index       : 1 2 3 4 5 6 7

*/

const int MAXN=200005;
vector<int> adj[MAXN];

int tin[MAXN];
int tout[MAXN];
int timer = 0;

vector<int> euler;

void dfs(int node , int parent){
    tin[node]=timer;
    euler.push_back(node);
    timer++;

    for(int child : adj[node]){
        if(child != parent){
            dfs(child , node);
        }
    }
    
    tout[node]=timer-1;
}

/*
timer - 1 : because we were always incrementing timer after pushing node to euler array
          : last node in the subtree is timer - 1

Now : any query :
    : for(int i=tin[node]; i<=tout[node]; i++)
    : each query : O(logN)

Note : after Euler's Tour , every query becomes range query : enwick & Segment tree handles them the best
*/
