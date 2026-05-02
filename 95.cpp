// Day 95 - Q1: Bucket Sort (Float Values 0-1)
// Topic: Bucket Sort, Pigeonhole Principle
// Time: O(n) avg, Space: O(n)
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n; cin>>n;
    vector<float> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    vector<vector<float>> b(n);
    for(int i=0;i<n;i++) b[(int)(n*a[i])].push_back(a[i]);
    for(int i=0;i<n;i++) sort(b[i].begin(),b[i].end());
    int k=0;
    for(int i=0;i<n;i++) for(float x:b[i]) a[k++]=x;
    for(int i=0;i<n;i++){ cout<<fixed<<setprecision(2)<<a[i]; if(i<n-1) cout<<" "; }
    cout<<endl; return 0;
}
