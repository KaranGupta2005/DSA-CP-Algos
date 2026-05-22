#include <bits/stdc++.h>
using namespace std;

/*
Rotating Callipers
- Two supporting lines rotate around the convex hull , as one points moves the optimal opposite point also moves monotonically
- applied after computing the convex hull ( polygon is convex , points in counterclockwise , no duplicate last point)
- The farthest points always lie on the convex hull and doesn't involve interior points

Antipodal Points
- for each edge , find the farthest point from that edge

Observation
- For convex polygon:
    - If:
        Area(i,i+1,j+1)>Area(i,i+1,j) then advance j.

- Whenever you see:
    - Maximum / farthest pair of points
    - Diameter of a polygon
    - Width / Minimum distance between two parallel tangents / supporting lines
    - Antipodal points
*/

// Diameter of a polygon
// Given a convex polygon with vertices in counter-clockwise order, find the diameter (maximum distance between any two vertices).

struct Point{
    int x,y;
};

long long cross(Point a, Point b, Point c) {
    return 1LL*(b.x - a.x) * (c.y - a.y) - 1LL*(b.y - a.y) * (c.x - a.x);
}

double dist(Point a, Point b) {
    long long dx=a.x-b.x, dy=a.y-b.y;
    return sqrt(dx*dx+dy*dy);
}

double diameter(vector<Point> &hull) {
    int n=hull.size();

    if(n==1) return 0.0;
    if(n==2) return dist(hull[0], hull[1]);

    double ans=0;
    int j=1;

    for(int i=0;i<n;i++){
        int ni=(i+1)%n;

        while(abs(cross(hull[i],hull[ni],hull[(j+1)%n])) > abs(cross(hull[i],hull[ni],hull[j]))){
            j=(j+1)%n;
        }
        
        ans=max(ans,dist(hull[i],hull[j]));
        ans=max(ans,dist(hull[ni],hull[j]));
    }
    
    return ans;
}

double width(vector<Point> &hull) {
    int n=hull.size();

    if(n<=2) return 0.0;
    
    double ans=1e18;
    int j=1;

    for(int i=0;i<n;i++){
        int ni=(i+1)%n;
        
        //maximise area
        while(abs(cross(hull[i],hull[ni],hull[(j+1)%n])) > abs(cross(hull[i],hull[ni],hull[j]))){
            j=(j+1)%n;
        }
        
        // edge length
        double edge=dist(hull[i],hull[ni]);

        // perpendicular length->width
        double width=abs(cross(hull[i],hull[ni],hull[j]))/edge;
        
        ans=min(ans,width);
    }
    
    return ans;
}
