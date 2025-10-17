#include<bits/stdc++.h>
using namespace std;
void qs(vector<int> &a,int l,int r){
    int p=a[(l+r)/2];
    int i=l;
    int j=r;
    while(i<j){
        while(a[i]>p) i++;
        while(a[j]<p) j--;
        if(i<=j){
            swap(a[i],a[j]);
            i++; j--;
        }
    }
    if(j>l)
        qs(a,l,j);
    if(i<r)
        qs(a,i,r);
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int> > a(m,vector<int> (n));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            cin>>a[j][i];
    }
    for(int i=0;i<m;i++){
        qs(a[i],0,n-1);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            cout<<a[j][i]<<' ';
        cout<<endl;
    }
}