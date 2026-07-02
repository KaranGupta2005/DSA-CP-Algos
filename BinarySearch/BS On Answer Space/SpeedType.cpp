#include <bits/stdc++.h>
using namespace std;

/*
Type 3: Rate/Speed Type
- Find minimum speed / rate to complete task in h hours
- we need to find first true : "min"
- Intuition:
    - Can we finish the work with this speed in required time ( <= h )
    - if speed = k ; time required : ceil(pile/k) : (pile+k-1)/k
*/

bool canEat(vector<int>& piles , int speed , int h){
    int time=0;

    for(auto &it:piles){
        time+=(it+speed-1)/speed;

        if(time>h) return false;
    }
    
    return true;
}

int minEatingSpeed(vector<int>& piles, int h) {
    int low=1;
    int high=*max_element(piles.begin(),piles.end());

    int ans=high;

    while(low<=high){
        int mid=low+(high-low)/2;
        if(canEat(piles,mid,h)){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }

    return ans;
}
