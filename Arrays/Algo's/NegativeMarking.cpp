#include <bits/stdc++.h>
using namespace std;

/*
- Used when all the elements of array are in range [1, n]
- Each element can be treated like an index
- Mark elements as negative to indicate presence
- used to find duplicates in an array
*/

int findDuplicate(vector<int>& arr) {
    int n = arr.size();
    
    // Phase 1: Mark elements as negative
    for (int i = 0; i < n; i++) {
        int index = abs(arr[i]);
        if (arr[index] < 0) {
            return index;  // Duplicate found
        }
        arr[index] = -arr[index];
    }
    
    // Phase 2: Restore original array
    for (int i = 0; i < n; i++) {
        arr[i] = abs(arr[i]);
    }
    
    return -1;  // No duplicate found
}

