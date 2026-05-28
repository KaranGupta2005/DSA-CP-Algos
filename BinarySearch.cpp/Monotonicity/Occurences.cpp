#include <bits/stdc++.h>
using namespace std;

/*
First Occurence-> First True
- When we find target:
    - store answer
    - continue searching LEFT
- Because maybe earlier occurrence exists.

Last Occurence-> Last True
- When we find target:
    - store answer
    - continue searching RIGHT
- Because maybe latter occurrence exists.

Total frequency of an element -> (Last-First+1)
*/

int firstOccurrence(vector<int>& arr, int target) {

    int low = 0;
    int high = arr.size() - 1;

    int ans = -1;

    while(low <= high) {

        int mid =
            low + (high - low) / 2;

        if(arr[mid] == target) {

            ans = mid;

            // move left
            high = mid - 1;
        }

        else if(arr[mid] < target) {
            low = mid + 1;
        }

        else {
            high = mid - 1;
        }
    }

    return ans;
}

int lastOccurrence(vector<int>& arr, int target) {

    int low = 0;
    int high = arr.size() - 1;

    int ans = -1;

    while(low <= high) {

        int mid =
            low + (high - low) / 2;

        if(arr[mid] == target) {

            ans = mid;

            // move right
            low = mid + 1;
        }

        else if(arr[mid] < target) {
            low = mid + 1;
        }

        else {
            high = mid - 1;
        }
    }

    return ans;
}