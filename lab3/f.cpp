#include<bits/stdc++.h>
using namespace std;
int binpoisk(vector<int> &a,int p){
    int l=0,r=a.size(),m;
    while(l<r){
        m=l+(r-l)/2;
        if(a[m]<=p)
            l=m+1;
        else r=m;
    }
    return l;
}
int main(){
    int n,r,p;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a.begin(),a.end());
    vector<int> s(n); s[0]=a[0];
    for(int i=1;i<n;i++) s[i]=a[i]+s[i-1];
    cin>>r;
    while(r--){
        cin>>p;
        int i=binpoisk(a,p);
        if(i==0) cout<<0<<' '<<0<<endl;
        else
        cout<<i<<' '<<s[i-1]<<endl;
    }
}