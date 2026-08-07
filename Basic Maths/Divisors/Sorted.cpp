#include <bits/stdc++.h>
using namespace std;

vector<int> getDivisors(int n){

    vector<int> small , large;

    for(int d=1 ; 1LL*d*d <= n ; d++){

        if(n%d==0){
            small.push_back(d);

            if(n/d != d){
                large.push_back(n/d);
            }
        }
    }

    reverse(large.begin() , large.end());
    small.insert(small.end() , large.begin() , large.end());

    return small;
}