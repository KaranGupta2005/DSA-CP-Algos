#include <bits/stdc++.h>
using namespace std;

/*
Deque- Double Ended Queue
- can pop_front , pop_back
- can push_front , push_back

- can access front and back in O(1)
- helps us remove useless elements efficiently unlike queue

- Monotonic Deque
-> increasing order maintained: to track Min Value
-> decreasing order maintained: to track Max Value
*/

/*
Pattern:
- subarray/window + (max/min in each window) + (dynamic size)
= always use deque
*/

int generalStructure(vector<int>& arr){
    deque<int> maxD, minD;
    int l = 0;
    int ans = 0;

for(int r = 0; r < arr.size(); r++) {

    // maintain max deque
    while(!maxD.empty() && arr[maxD.back()] <= arr[r])
        maxD.pop_back();
    maxD.push_back(r);

    // maintain min deque
    while(!minD.empty() && arr[minD.back()] >= arr[r])
        minD.pop_back();
    minD.push_back(r);

    // shrink window if condition breaks
    while(/* invalid condition */) {
        if(maxD.front() == l) maxD.pop_front();
        if(minD.front() == l) minD.pop_front();
        l++;
    }

    ans = max(ans, r - l + 1);
}
    return ans;
}