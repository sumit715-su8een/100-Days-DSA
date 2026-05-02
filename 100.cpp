// Day 100 - Q1: Count Inversions in Array (Merge Sort)
// Topic: Fenwick Tree, Merge Sort, Inversion Counting
// Time: O(n log n), Space: O(n)
#include<bits/stdc++.h>
using namespace std;
long long mergeCount(vector<int>&a, int l, int m, int r){
    long long inv=0;
    vector<int> tmp;
    int i=l, j=m+1;
    while(i<=m && j<=r){
        if(a[i]<=a[j]) tmp.push_back(a[i++]);
        else{ inv+=(long long)(m-i+1); tmp.push_back(a[j++]); }
    }
    while(i<=m) tmp.push_back(a[i++]);
    while(j<=r) tmp.push_back(a[j++]);
    for(int k=l;k<=r;k++) a[k]=tmp[k-l];
    return inv;
}
long long mergeSort(vector<int>&a, int l, int r){
    long long inv=0;
    if(l<r){
        int m=l+(r-l)/2;
        inv+=mergeSort(a,l,m);
        inv+=mergeSort(a,m+1,r);
        inv+=mergeCount(a,l,m,r);
    }
    return inv;
}
int main(){
    int n; cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    cout<<mergeSort(a,0,n-1)<<endl;
    return 0;
}
