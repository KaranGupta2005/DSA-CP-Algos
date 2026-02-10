#include <bits/stdc++.h>
using namespace std;

double power(double a, int n){
    if(n==0) return 1.0;

    double half=power(a,n/2);

    if(n%2==0){
        return half*half;
    }
    else{
        return half*half*a;
    }
}

double powerNeg(double a, int n){
    if(n<0){
        a=1.0/a;
        n=-n;
    }
    return power(a,n);
}

int main(){
    double a;
    int n;
    cin>>a>>n;
    cout<<powerNeg(a,n)<<endl;
    return 0;
}
