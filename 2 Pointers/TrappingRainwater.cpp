#include <bits/stdc++.h>
using namespace std;

/*
Water gets trapped between the bars
- for that we need a left and a right boundary
- the min(left,right) will determine the water level, since water will overflow after the shorter boundary
- left , right-> maximum height seen so far from left and right
*/
int prefixArr(vector<int> &arr) {
    int n=arr.size();
    vector<int> leftMax(n,0);
    vector<int> rightMax(n,0);

    for(int i=1;i<n;i++){
        leftMax[i]=max(leftMax[i-1],arr[i]);
    }

    for(int i=n-2;i>=0;i--){
        rightMax[i]=max(rightMax[i+1],arr[i]);
    }

    int water=0;
    for(int i=0;i<n;i++){
        water += min(leftMax[i],rightMax[i]) - arr[i];
    }
    
    return water;
}
// Time Complexity: O(n)
// Space Complexity: O(n)-> two auxiliary arrays are used

/*
Two Pointer Approach
- use two pointers, one at start and one at end
- maintain leftMax and rightMax
- move the pointer with smaller height-> or the pointer that limits the height
*/
int twoPointer(vector<int> &arr) {
    int n=arr.size();
    int leftMax=0 , rightMax=0;

    int water=0;

    int i=0 , j=n-1;
    while(i<=j){
        if(arr[i]<=arr[j]){
            if (arr[i]>=leftMax){
                leftMax=arr[i];
            }
            else{
                water += leftMax - arr[i];
            }
            i++;
        }
        else{
            if(arr[j]>=rightMax){
                rightMax=arr[j];
            }
            else{
                water += rightMax - arr[j];
            }
            j--;
        }
    }
    
    return water;
}
// Time Complexity: O(n)
// Space Complexity: O(1)

/*
Monotonic Stack Approach
- we maintain a decreasing stack , in other to track the previous elements whenever a right boundary is found
- if the ith index > stack.top() -> we have found a right boundary
- water trapped== 
left boundary(st.top())   right boundary
      |                 |
      v                 v
      █                 █
       █               █
        █   valley    █
            (top)
*/
int monotonicStack(vector<int> &arr) {
    int n=arr.size();
    stack<int> st;

    int water=0;
    for(int i=0;i<n;i++){
        while(!st.empty() && arr[i]>arr[st.top()]){
            int top=st.top();
            st.pop();

            if(st.empty()) break; // no left boundary -> no water trapped

            int distance= i - st.top() - 1; // R-L-1 : including only the space between them
            int height= min(arr[i],arr[st.top()]) - arr[top]; // min(left,right) - current height
            
            water += distance * height;
        }
        st.push(i);
    }
    return water;
}
