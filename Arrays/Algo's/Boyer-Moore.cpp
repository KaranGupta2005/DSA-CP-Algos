#include <bits/stdc++.h>
using namespace std;

/*
Boyer-Moore Majority Vote Algorithm

- If an element is candidate in becoming majority element : it's freq>(n/2)
- Verify the candidate by counting its freq at the last
*/

int majorityElement(vector<int>& nums) {
    int candidate=0;
    int count=0;

    for(auto &it:nums){
        if(count==0){
            candidate=it;
        }

        if(it==candidate){
            count++;
        }else{
            count--;
        }
    }

    int count=0;
    for(auto &it:nums){
        if(it==candidate){
            count++;
        }
    }

    return (count > nums.size()/2) ? candidate : -1;
}