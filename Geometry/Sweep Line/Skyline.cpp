#include <bits/stdc++.h>
using namespace std;

/*
Sweep Line
- Instead of checking all the things against everything -> O(n^2)
- We move a line from left to right (sweep) and we consider the currently relevant objects
- Can be possible if: nothing changes much between two consecutive events

Universal Structure
- Convert the problem to events
- sort the events acc to edge cases
- sweep through them
- maintain the necessary data structure
- update the answer

Active Data Structure

1. Map : used for prefix sum / difference array problems
2. multiset : used when duplicates matter and we need (max/min)-> to maintain active heights in skyline problem
3. set/BST : used when we need to maintain order / nearest neighbours
4. priority queue : used to maintain ending interval -> car pooling / meeting rooms
5. segment trees : range updates , rectangle union , coverage problems
*/

/*
Skyline Problem Edge Cases:
1. Two events start at same X : always process the one with higher height first
2. One event starts and one ends at same X : process start before end
3. Two events end at same X : process the one with lower height first
4. At the start -> at the ground level -> push 0 to the multiset
*/

vector<vector<int>> getSkyline(vector<vector<int>>& buildings){

    vector<pair<int,int>> events;
    for(auto &it: buildings){
        int l=it[0];
        int r=it[1];
        int h=it[2];
        
        // start event
        events.push_back({l, -h});
        // end event
        events.push_back({r, h});
    }

    sort(events.begin(), events.end());

    multiset<int> active;
    active.insert(0); // ground level

    vector<vector<int>> ans;

    int prevMax=0;

    for(auto &it:events){
        int x=it.first;
        int h=it.second;
        
        if(h<0){
            active.insert(-h);
        }
        else{
            active.erase(active.find(h));
        }
        
        int currMax=*active.rbegin();

        // skyline changes
        if(currMax!=prevMax){
            ans.push_back({x, currMax});
            prevMax=currMax;
        }
    }
    
    return ans;
}