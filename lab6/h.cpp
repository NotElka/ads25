#include<bits/stdc++.h>
using namespace std;

void qs(vector<string> &a,int l,int r){
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
int main(){
    int n;
    cin>>n;
    vector<string> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    string s;
    cin>>s;
    qs(a,0,n-1);
    int ans=0;
    for(int i=0;i<n;i++){
        if(s<a[i]){
            ans=i;
            break;
        }
    }
    cout<<a[ans];
}


