// Day 92 - Q1: Quick Sort Implementation
// Topic: Sorting, Quick Sort
// Time: O(n log n) avg, Space: O(log n)
#include<bits/stdc++.h>
using namespace std;
int partition(int a[],int low,int high){
    int pivot=a[high],i=low-1;
    for(int j=low;j<high;j++) if(a[j]<=pivot) swap(a[++i],a[j]);
    swap(a[i+1],a[high]); return i+1;
}
void quickSort(int a[],int low,int high){
    if(low<high){ int pi=partition(a,low,high); quickSort(a,low,pi-1); quickSort(a,pi+1,high); }
}
int main(){
    int n; cin>>n; int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    quickSort(a,0,n-1);
    for(int i=0;i<n;i++){ cout<<a[i]; if(i<n-1) cout<<" "; }
    cout<<endl; return 0;
}
