// Day 98 - Q1: Merge Overlapping Intervals
// Topic: Intervals, Sorting, Greedy
// Time: O(n log n), Space: O(n)
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n; cin>>n;
    vector<pair<int,int>> v(n);
    for(int i=0;i<n;i++) cin>>v[i].first>>v[i].second;
    sort(v.begin(),v.end());
    vector<pair<int,int>> res;
    res.push_back(v[0]);
    for(int i=1;i<n;i++){
        if(v[i].first<=res.back().second)
            res.back().second=max(res.back().second,v[i].second);
        else res.push_back(v[i]);
    }
    for(auto& p:res) cout<<p.first<<" "<<p.second<<endl;
    return 0;
}
