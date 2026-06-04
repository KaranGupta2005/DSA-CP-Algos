#include <bits/stdc++.h>
using namespace std;

/*
- Used to sort an array containing only 0, 1, and 2 (Dutch National Flag problem)
- Three pointers approach: low (0s), mid (1s), high (2s)
- The original array acts as visited array in-place

- Maintains:
    [0...low-1]      = 0
    [low...mid-1]    = 1
    [mid...high]     = unknown
    [high+1...n-1]   = 2
*/

void sortColors(vector<int>& nums) {

    int low = 0;
    int mid = 0;
    int high = nums.size() - 1;

    while(mid <= high){

        if(nums[mid] == 0){

            swap(nums[low], nums[mid]);
            low++;
            mid++;
        }

        else if(nums[mid] == 1){

            mid++;
        }

        else{

            swap(nums[mid], nums[high]);
            high--;
            // DON'T increment mid : coz don't know whether that element comes out to be 2
        }
    }
}