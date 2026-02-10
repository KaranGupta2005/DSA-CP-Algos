#include <bits/stdc++.h>
using namespace std;

//stein algorithm / subtraction based Euclidean algorithm
int gcd(int a, int b){
    while(a!=b){
        if(a>b) a=a-b;
        else b=b-a;
    }
    return a;
}

int lcm(int a, int b){
    return (a*b)/gcd(a,b);
}

int main(){
    int num1,num2;
    cout<<"Enter two numbers: ";
    cin>>num1>>num2;
    cout<<"GCD: "<<gcd(num1,num2)<<endl;
    cout<<"LCM: "<<lcm(num1,num2)<<endl;
    return 0;
}