#include<bits/stdc++.h>
using namespace std;
int barashek(vector<vector<int> > &a,int m){
    int cnt=0;
    for(int i=0;i<a.size();i++){
        if(a[i][0]<=m && a[i][1]<=m)
            cnt++;
        }
    return cnt;
}
int main(){
    int n,k,r=0;
    cin>>n>>k;
    int x,y,x1,y1;
    vector<vector<int> > a(n,vector<int> (2));
    for(int i=0;i<n;i++){
        cin>>x>>y>>x1>>y1;
        a[i][0]=x1;
        a[i][1]=y1;
        r=max(max(r,y1),x1);
    }
    int l=0;
    int m;
    while(l<r){
        m=l+(r-l)/2;
        if(barashek(a,m)<k)
            l=m+1;
        else    r=m;
    }
    cout<<l;

}