#include <bits/stdc++.h>
using namespace std;

/*if you are asked to find:
1. the next lexicographically greater permutation
2. the next greater number with the same set of digits
3. the next greater string with the same set of characters / permutation
*/

// (increasing order of digits) | (non-increasing/decreasing order of digits)

void nextPermutation(vector<int>& nums) {
    int n=nums.size();
    int pivot=-1;

    // finding the pivot , the index after which the number are arranged in decreasing order ( largest possible way )
    for(int i=n-2;i>=0;i--){
        if(nums[i]<nums[i+1]){
            pivot=i;
            break;
        }
    }

    // if no pivot
    // i.e. elements are in decreasing order
    if(pivot==-1){
        reverse(nums.begin(),nums.end());
        return;
    }

    // find the number just greater than the one at pivot
    // since in the right side -> decreasing order -> scan from right to left
    for(int i=n-1;i>pivot;i--){
        if(nums[i]>nums[pivot]){
            swap(nums[i],nums[pivot]);
            break;
        }
    }

    // reverse the decreasing part
    reverse(nums.begin()+(pivot+1),nums.end());

}

int main(){
    int len;
    vector<int> arr;

    cout << "Enter the length of the array: ";
    cin >> len;

    for(int i = 0; i < len; i++){
        int data;
        cin >> data;
        arr.push_back(data);
    }

    nextPermutation(arr);

    cout << "Next permutation: ";
    for(int x : arr) cout << x << " ";
}

