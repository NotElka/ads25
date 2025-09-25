#include<bits/stdc++.h>
using namespace std;
int proverka(vector<int> a,int b){
    int k=0;
    for(int i=0;i<a.size();i++){
        k+=ceil(a[i]/(b/1.0));
    }
    return k;
}
int main(){
    int n,f,l=1,r=0;
    cin>>n>>f;
    vector<int> c(n);
    for(int i=0;i<n;i++){
        cin>>c[i];
        r=max(c[i],r);
    }
    int m;
    while(l<r){
        m=l+(r-l)/2;
        if(f<proverka(c,m)) 
            l=m+1;
        else 
            r=m;
    }
    cout<<l;
}