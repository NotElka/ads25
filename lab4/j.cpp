#include<bits/stdc++.h>
using namespace std;
void solve(vector<int> &a,int l,int r){
    int mid=(l+r)/2;
    if(r-l==1){return;}
    cout<<a[mid]<<' ';
    solve(a,l,mid);
    solve(a,mid,r);
}

int main(){
    int n;
    cin>>n;
    n=pow(2,n)-1;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a.begin(),a.end());
    solve(a,0,n);
    cout<<a[0];
}