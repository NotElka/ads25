#include<bits/stdc++.h>
using namespace std;

void merge(vector<int> &a,int l,int r){
    int m=(l+r)/2;
    vector<int> ls(m-l+1);
    vector<int> rs(r-m);
    for(int i=0;i<m-l+1;i++)
        ls[i]=a[l+i];
    for(int i=0;i<r-m;i++)
        rs[i]=a[m+1+i];
    int i=0,j=0;
    while(i<ls.size() && j<rs.size()){
        if(ls[i]<rs[j]){
            a[l+i+j]=ls[i];
            i++;
        }
        else{
            a[l+i+j]=rs[j];
            j++;
        }
    }
    while(i<ls.size()){
        a[l+i+j]=ls[i];
        i++;
    }
    while(j<rs.size()){
        a[l+i+j]=rs[j];
        j++;
    }
}
void merge_sort(vector<int> &a,int l,int r){
    if(l<r){
    merge_sort(a,l,(l+r)/2);
    merge_sort(a,(l+r)/2+1,r);
    merge(a,l,r);
}
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
    merge_sort(a,0,n-1);
    merge_sort(b,0,m-1);
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