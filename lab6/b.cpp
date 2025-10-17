#include<bits/stdc++.h>
using namespace std;

void qs(vector<int> &a,int l,int r){
    int p=(l+r)/2;
    int i=l;
    int j=r;
    while(i<j){
        while(a[p]>a[i]) i++;
        while(a[p]<a[j]) j--;
        if(i<=j){
            swap(a[i],a[j]);
            i++;
            j--;
        }
    }
    if(l<j)
        qs(a,l,j);
    if(i<r)
        qs(a,i,r);
}
void print(vector<int> &ans){
    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<' ';
    }
int main(){
    int n,m;
    cin>>n>>m;
    if(n>0 && m>0){
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    vector<int> b(n);
    for(int i=0;i<m;i++) cin>>b[i];
    qs(a,0,n-1);
    qs(b,0,m-1);
    int i=0,j=0;
    vector<int> ans;
    while(i<n && j<m){
        if(a[i]==b[j]){
            ans.push_back(a[i]);
            i++; j++;
        }
        else if(a[i]>b[j])
            j++;
        else 
            i++;
    }
    print(ans);}
    else{
        n=max(n,m);
        vector<int> a(n);
        for(int i=0;i<n;i++) cin>>a[i];
    }
    cout<<endl;
}