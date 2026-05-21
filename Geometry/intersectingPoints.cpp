#include<bits/stdc++.h>
using namespace std;

// Intersecting lines
/*
Given 2 lines in 2D plane AB and CD
- If the 2 lines lie in different directions , then they intersect
- Special check for collinear overlapping , whether the are disjoint or intersect at some point
- orient(A,B,C) × orient(A,B,D) ≤ 0 AND orient(C,D,A) × orient(C,D,B) ≤ 0
    - orient(A,B,C) × orient(A,B,D) ≤ 0 : Whether C , D lie on opposite side of AB
    - orient(C,D,A) × orient(C,D,B) ≤ 0 : Whether A , B lie on opposite side of CD

- in case of collinear points: check whether the point lies in the segment range
*/
struct Point {
    int x, y;
};

long long cross(Point a , Point b , Point c) {
    return (1LL * (b.x - a.x) * (c.y - a.y) - 1LL * (b.y - a.y) * (c.x - a.x));
}

bool onSegment(Point a , Point b , Point c) {
    return min(a.x,b.x) <= c.x && c.x <= max(a.x,b.x) &&
           min(a.y,b.y) <= c.y && c.y <= max(a.y,b.y);
}

bool intersect(Point a , Point b , Point c , Point d) {
    long long o1=cross(a,b,c);
    long long o2=cross(a,b,d);
    long long o3=cross(c,d,a);
    long long o4=cross(c,d,b);

    //proper intersection
    if((o1 * o2) < 0 && (o3 * o4) < 0) {
        return true;
    }

    //collinear case
    if(o1 == 0 && onSegment(a,b,c)) {
        return true;
    }
    if(o2 == 0 && onSegment(a,b,d)) {
        return true;
    }
    if(o3 == 0 && onSegment(c,d,a)) {
        return true;
    }
    if(o4 == 0 && onSegment(c,d,b)) {
        return true;
    }

    return false;
}