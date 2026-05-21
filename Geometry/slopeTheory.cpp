#include<bits/stdc++.h>
using namespace std;

/*
If we are going to find the maximum points that line on a line , 
-Cross Product
    - Will lead to the brute force O(n^3) time complexity

-Slope Theory
    - We will fix a point and find out the slopes of rest of the points with respect to the acnchor point
    - Will not store slope in floating point (dy/dx) - instead store in reduced form (dy/gcd, dx/gcd)
    - Also take care of vertical line , horizontal line and sign convention normalization
*/

int gcd(int a , int b){
    if(b==0) return a;
    return gcd(b,a%b);
}

int maxPoints(vector<vector<int>>& points) {
    int n=points.size();
    if(n<=2) return n; // atleast 2 points are required to form a line

    int ans=0;

    for(int i=0;i<n;i++){
        int currMax=0;
        map<pair<int,int>,int> mp;

        for(int j=i+1;j<n;j++){
            int dx=points[j][0]-points[i][0];
            int dy=points[j][1]-points[i][1];

            // vertical line case
            if(dx==0){
                dy=1;
            }

            // horizontal line case
            else if(dy==0){
                dx=1;
            }

            else{
                // gcd normalization
                int g=gcd(abs(dx),abs(dy));
                dx/=g;
                dy/=g;

                // sign convention
                if(dx<0){
                    dx=-dx;
                    dy=-dy;
                }
            }
            
            mp[{dx,dy}]++;
            currMax=max(currMax,mp[{dx,dy}]);
        }
        
        ans=max(ans,currMax+1); // +1: anchor point also included
    }
    
    return ans;
}