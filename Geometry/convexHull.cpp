#include <bits/stdc++.h>
using namespace std;

/*
Convex Hull:
- Smallest polygon using all the enclosed points in a 2d plane
- It is used wherever you see:
  - Farthest pair of points
  - Enclosing Points
  - Minimum Perimeter
  - Outer Boundary
  - Geometry Optimization
  

| Algorithm       | Also Called        |
| --------------- | ------------------ |
| Graham Scan     | Graham’s algorithm |
| Monotonic Chain | Andrew’s algorithm |

*/

// Graham's Scan
/*
- O(nlogn) time complexity
- O(n) space complexity

1. Find out the pivot / lowest  element (element with the smallest  coordinate) : O(n)
2. Angular Sort: Merge / Heap sort onl , just sorts on the basis of the polar angle of the points relative to the pivot element : O(nlogn)
3. Amortized Scan: Using a stack or heap: to filter out all the right / collinear turns : O(n)

Intuition: Walk around points in circular order.
If you bend inward: not convex → remove point

Core Graham Logic : 
while (hull.size() >= 2 &&
       cross(hull[end-2], hull[end-1], p) <= 0) 
{
    hull.pop_back();
}

- not used much because polar sorting is precision heavy and complex for collinear points
*/

// Andrew's Monotic Chain
/*
- O(nlogn) time complexity
- O(n) space complexity

1. Sort points lexicographically ( Primarily on the basis of x , Secondary on the basis of y) : O(nlogn)
2. Build lower and upper hulls : O(n) : using the same orientation logic as Graham's Scan

Intuition: Build bottom-to-top and top-to-bottom chains.
*/

struct Point{
    int x,y;
};

long long cross(Point a , Point b , Point c){
    return ((b.x-a.x)*(c.y-a.y) - (b.y-a.y)*(c.x-a.x));
}

//if two points are same, cross product automatically becomes 0

vector<Point> convexHull(vector<Point>& pts){

    sort(pts.begin(), pts.end() , [](const Point& a, const Point& b){
        if(a.x == b.x) return a.y<b.y;
        return a.x<b.x;
    });

    vector<Point> hull;

    // lower hull
    for(auto p:pts){
        while(hull.size()>=2 && cross(hull[hull.size()-2], hull[hull.size()-1], p) <= 0){
            hull.pop_back();
        }
        hull.push_back(p);
    }

    int lowerHull=hull.size();

    // upper hull
    for(int i=pts.size()-2;i>=0;i--){
        while(hull.size()>lowerHull && cross(hull[hull.size()-2], hull[hull.size()-1], pts[i]) <= 0){
            hull.pop_back();
        }
        hull.push_back(pts[i]);
    }

    hull.pop_back(); // remove duplicate pivot point

    return hull;
}

/*
cross(...) <= 0
This removes:
- right turns
- collinear points
So your hull keeps only extreme corner points: minimal convex polygon.

If you want all boundary points included:
use < 0 instead.
*/

// Triangle with the maximum area lies on the convex hull