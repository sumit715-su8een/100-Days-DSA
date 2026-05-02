// Day 94 - Q1: Counting Sort Implementation
// Topic: Counting Sort
// Time: O(n+k), Space: O(n+k)
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n; cin>>n;
    vector<int> a(n); int mx=0;
    for(int i=0;i<n;i++){ cin>>a[i]; mx=max(mx,a[i]); }
    vector<int> cnt(mx+1,0);
    for(int i=0;i<n;i++) cnt[a[i]]++;
    for(int i=1;i<=mx;i++) cnt[i]+=cnt[i-1];
    vector<int> out(n);
    for(int i=n-1;i>=0;i--){ out[cnt[a[i]]-1]=a[i]; cnt[a[i]]--; }
    for(int i=0;i<n;i++){ cout<<out[i]; if(i<n-1) cout<<" "; }
    cout<<endl; return 0;
}
