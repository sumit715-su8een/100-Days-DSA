// Day 97 - Q1: Meeting Rooms Scheduling (Min Rooms Needed)
// Topic: Intervals, Priority Queue, Greedy
// Time: O(n log n), Space: O(n)
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n; cin>>n;
    vector<pair<int,int>> v(n);
    for(int i=0;i<n;i++) cin>>v[i].first>>v[i].second;
    sort(v.begin(),v.end());
    priority_queue<int,vector<int>,greater<int>> pq;
    for(auto& m:v){
        if(!pq.empty() && pq.top()<=m.first) pq.pop();
        pq.push(m.second);
    }
    cout<<pq.size()<<endl;
    return 0;
}
