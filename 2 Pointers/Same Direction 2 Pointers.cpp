#include <bits/stdc++.h>
using namespace std;

/*
Same Direction /Fast-Slow Pointers
- Here both pointers move in the same direction
- Useful for finding patterns, cycles, or specific properties in a single pass
- fast pointer explores the array , while slow maintains the valid / processed region
*/

/*
Remove Duplicates
- We are given an array and it is not possible to change the length of it 
- So if there are k unique elements , then the first k elements should be unique
- new length = slow + 1

- below is the generalized code : even if are able to remove some elements and each element may appear atmost k times
- then : if(slow<k || nums[fast] != nums[slow-k])
*/
int removeDuplicates(vector<int>& nums){
    int slow=0;

    for(int fast=0 ; fast<nums.size() ; fast++){
        if(slow<1 || nums[fast] != nums[slow-1]){
            nums[slow] = nums[fast];
            slow++;
        }
    }
    return slow;
}

/*
Remove ELement
- the first k elements should not be equal to val
- return k
*/
int removeElement(vector<int>& nums, int val) {
    int slow=0;
    int n=nums.size();

    for(int fast=0 ; fast<n ; fast++){
        if(nums[fast]!=val){
            nums[slow]=nums[fast];
            slow++;
        }
    }

    return slow;
}

/*
Move Zeros
- Move all the zeros to the end of the array
- [0 .... slow-1] : non zero elements
- [slow .... n-1] : zeros
*/
void moveZeros(vector<int>& nums) {
    int slow=0;
    int n=nums.size();

    for(int fast=0 ; fast<n ; fast++){
        if(nums[fast]!=0){
            swap(nums[slow], nums[fast]);
            slow++;
        }
    }
}

/*
Partition Array
- Used for even/odd ; positive/negative ; removing invalid elements ; partition by parity
*/
void partitionArray(vector<int>& nums) {
    int slow=0;
    int n=nums.size();

    for(int fast=0 ; fast<n ; fast++){
        if(conditionOn(nums[fast])){
            swap(nums[slow], nums[fast]);
            slow++;
        }
    }
}