#include <bits/stdc++.h>
using namespace std;

/*
Closest Pair of Points / Minimum Euclidean Distance Between Points
- This is a classic paradigm of Divide and Conquer
- Firstly sort the points acc to x coordinate , so that left and right halves can be formed
- Then recursively compute:
    - smallest distance in left → dL
    - smallest distance in right → dR
- d=min(dL,dR)
- Now only one possibility remains that one points lies in left and other in right ( closer to middle strip ) 
    - so we will Build strip: all points whose x-distance from midline < d
- Sort acc to the y coordinate
- For each point in strip, check its distance to next 7 points only ( atmost 7 can be closer )
*/

struct Point{
    double x , y;
};

double dist(Point a , Point b){
    double dx=(a.x - b.x);
    double dy=(a.y - b.y);
    return sqrt(dx*dx + dy*dy);
}

bool cmpX(Point a , Point b){
    return a.x < b.x;
}

bool cmpY(Point a , Point b){
    return a.y < b.y;
}

double bruteForce(vector<Point>& pts , int l , int r){
    double ans=1e18;

    for(int i=l;i<=r;i++){
        for(int j=i+1;j<=r;j++){
            ans=min(ans,dist(pts[i],pts[j]));
        }
    }

    return ans;
}

double stripSolve(vector<Point>& strip , double d){
    int n=strip.size();
    double ans=d;

    sort(strip.begin(),strip.end(),cmpY);

    // check atmost 7 points -> atmost vertical displacement of d
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n && (strip[j].y - strip[i].y) < d ;j++){
            ans=min(ans,dist(strip[i],strip[j]));
        }
    }
    
    return ans;
}

double solve(vector<Point>& pts , int l , int r){

    // for small case -> bruteforce
    if((r-l)<=3){
        return bruteForce(pts , l , r);
    }

    int mid= l+(r-l)/2;
    double midX=pts[mid].x;

    double dL=solve(pts , l , mid);
    double dR=solve(pts , mid+1 , r);
    double d=min(dL,dR);

    // Build strip
    vector<Point> strip;

    for(int i=l;i<=r;i++){
        if(abs(pts[i].x - midX)<d){
            strip.push_back(pts[i]);
        }
    }

    return min(d , stripSolve(strip,d));

}

double closestPair(vector<Point>& pts){
    sort(pts.begin(),pts.end(),cmpX);
    return solve(pts , 0 , pts.size()-1);
}

