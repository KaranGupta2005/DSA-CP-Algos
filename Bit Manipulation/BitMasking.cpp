#include <bits/stdc++.h>
using namespace std;

//instead of representing a set of elements using an array , we can use a bitmask / number
//for a set of n elements ,there will be 2^n possible subsets each of n bits

// subset generation using bitmasking
void generateSubsets(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                cout << arr[j] << " ";
            }
        }
        cout << endl;
    }
}

//check membership using bitmasking
bool isMember(int mask, int pos) {
    return (mask & (1 << pos));
}

//add an element to the set
int addElement(int mask, int pos) {
    return (mask | (1 << pos));
}

//remove an element from the set
int removeElement(int mask, int pos) {
    return (mask & ~(1 << pos));
}

//toggle an element in the set
int toggleElement(int mask, int pos) {
    return (mask ^ (1 << pos));
}

//check if a set is empty
bool isEmpty(int mask) {
    return (mask == 0);
}

//check if a set is full
bool isFull(int mask, int n) {
    return (mask == (1 << n) - 1);
}

//intersection of two sets
int intersection(int mask1, int mask2) {
    return (mask1 & mask2);
}

//union of two sets
int unionSets(int mask1, int mask2) {
    return (mask1 | mask2);
}

//difference of two sets
int difference(int mask1, int mask2) {
    return (mask1 & ~mask2);
}

//symmetric difference of two sets
int symmetricDifference(int mask1, int mask2) {
    return (mask1 ^ mask2);
}

//complement of a set
int complement(int mask, int n) {
    return ((1 << n) - 1) ^ mask;
}

//iterating over all the submasks of a mask
void iterateSubmasks(int mask) {
    int submask = mask;
    while (submask > 0) {
        submask = (submask - 1) & mask;
    }
}

//smallest submask of a mask
int smallestSubmask(int mask) {
    return (mask & (-mask));
}

//largest submask of a mask
int largestSubmask(int mask) {
    return (mask & (mask - 1));
}


