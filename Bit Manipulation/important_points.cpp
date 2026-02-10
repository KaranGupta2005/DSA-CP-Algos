#include <bits/stdc++.h>
using namespace std;

// ith bit is set or not
bool isSet(int n,int i){
    return (n & (1 << i)) != 0;
}

//set ith bit
void setBit(int &n,int i){
    n = n | (1 << i);
}

//clear/unset ith bit
void clearBit(int &n,int i){
    n = n & ~(1 << i);
}

//toggle ith bit
void toggleBit(int &n,int i){
    n = n ^ (1 << i);
}

//check if a number is power of 2
bool isPowerOf2(int n){
    return (n>0 && (n & (n-1))==0);
}

//count set bits (Hamming weight method / Brian Kernighan's algorithm)
int countSetBits(int n){
    int count = 0;
    while(n>0){
        n=n&(n-1); // rightmost set bit ko clear krte jao
        count++;
    }

    return count;
}

//extract the rightmost set bit
int getRightmostSetBit(int n){
    return n & (-n);
}

//remove the rightmost set bit
int removeRightmostSetBit(int n){
    return n & (n-1);
}

//check if two numbers have opposite signs
bool oppositeSigns(int a,int b){
    return (a^b) < 0;
}

//swap two numbers without temporary variable
void swap(int &a,int &b){
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}

//check if ith bit is set directly
bool isIthBitSet(int n,int i){
    return ((n >> i) & 1);
}

//multiply by 2^k
int multiplyByPowerOf2(int n,int k){
    return n << k; // left shift by k positions
}

//divide by 2^k
int divideByPowerOf2(int n,int k){
    return n >> k; // right shift by k positions
}

