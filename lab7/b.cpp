#include<bits/stdc++.h>
using namespace std;
bool proverka(string a,string b){
    if(a.size()==b.size())
        return true;
    if(a.size()<b.size())
        return true;
    return false;
}
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
int main(){
    int n,b;
    cin>>n;
    vector<int > a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>b;
        a.push_back(b);
    }
    merge_sort(a,0,a.size()-1);
    for(int i=0;i<a.size();i++)
        cout<<a[i]<<' ';
}