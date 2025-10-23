#include<bits/stdc++.h>
using namespace std;

bool c(pair<int,vector<int > > a,pair<int,vector<int> > b){
    if(a.first==b.first)
        return a.second<b.second;
    if(a.first>b.first)
        return true;
    return false;
}

void merge(vector<pair<int,vector<int> > > &a,int l,int r){
    int m=(l+r)/2;
    vector<pair<int,vector<int > > > ls(m-l+1);
    vector<pair<int,vector<int > > > rs(r-m);
    for(int i=0;i<m-l+1;i++)
        ls[i]=a[l+i];
    for(int i=0;i<r-m;i++)
        rs[i]=a[m+1+i];
    int i=0,j=0,k=l;
    while(i<ls.size() && j<rs.size()){
        if(c(ls[i],rs[j])){
            a[k++]=ls[i];
            i++;
        }
        else{
            a[k++]=rs[j];
            j++;
        }
    }
    while(i<ls.size()){
        a[k++]=ls[i];
        i++;
    }
    while(j<rs.size()){
        a[k++]=rs[j];
        j++;
    }
}
void merge_sort(vector<pair<int,vector<int > > > &a,int l,int r){
    if(l<r){
    merge_sort(a,l,(l+r)/2);
    merge_sort(a,(l+r)/2+1,r);
    merge(a,l,r);
}
}

int main(){
    int n,m,x,s;
    cin>>n>>m;
    vector<pair<int,vector<int> > > a(n);
    for(int i=0;i<n;i++){
        a[i].first=0;
        for(int j=0;j<m;j++){
            cin>>x;
            a[i].first+=x;
            a[i].second.push_back(x);
        }
    }
    merge_sort(a,0,n-1);
    for(int i=0;i<n;i++){
        for(int j=0;i<m;j++)
        cout<<a[i].second[j]<<endl;
    }
}