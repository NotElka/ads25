#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    int l=0,r=n,m;
    int x;
    cin>>x;
    while(l<r){
        m=l+(r-l)/2;
        if(a[m]<x)
            l=m+1;
        else
            r=m;
    }
    if(a[l]==x)
    cout<<"Yes";
    else
    cout<<"No";
}