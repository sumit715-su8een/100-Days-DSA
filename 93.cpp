// Day 93 - Q1: Insertion Sort Implementation
// Topic: Sorting, Insertion Sort
// Time: O(n^2), Space: O(1)
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n; cin>>n; int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=1;i<n;i++){
        int key=a[i],j=i-1;
        while(j>=0&&a[j]>key){ a[j+1]=a[j]; j--; }
        a[j+1]=key;
    }
    for(int i=0;i<n;i++){ cout<<a[i]; if(i<n-1) cout<<" "; }
    cout<<endl; return 0;
}
