// Day 99 - Q1: Car Fleet Calculation
// Topic: Greedy, Sorting, Monotonic Stack Pattern
// Time: O(n log n), Space: O(n)
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, target; cin>>n>>target;
    vector<pair<int,int>> cars(n);
    for(int i=0;i<n;i++) cin>>cars[i].first>>cars[i].second;
    sort(cars.rbegin(),cars.rend());
    int fleets=0; double last=0;
    for(auto& c:cars){
        double t=(double)(target-c.first)/c.second;
        if(t>last){ fleets++; last=t; }
    }
    cout<<fleets<<endl;
    return 0;
}
