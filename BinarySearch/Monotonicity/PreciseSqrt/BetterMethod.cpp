#include <bits/stdc++.h>
using namespace std;

double sqrtPrecision(double x){
    double low=0;
    double high=x;

    double eps=1e-6; // for upto 6 decimal places

    while((high-low)>eps){
        double mid=low+(high-low)/2;
        
        if(mid*mid<x){
            low=mid;
        }else{
            high=mid;
        }
    }

    return low;
}