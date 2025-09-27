#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    vector<int> a(n+1);
    a[0]=0;
    cin>>a[1];
    for(int i=2;i<n+1;i++){
        cin>>a[i];
        a[i]+=a[i-1];
    }
    int ans=n+1;
    for(int i=0;i<n;i++){
    int l=i,r=n,m;
    while(l<r){
        m=l+(r-l)/2;
        if(a[m]-a[i]<k) l=m+1;
        else r=m; 
    }
    if(a[l]-a[i]>=k) ans=min(ans,l-i);
}
cout<<ans;
}