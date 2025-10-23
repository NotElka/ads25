#include<bits/stdc++.h>
using namespace std;
bool proverka(string a,string b){
    if(a.size()==b.size())
        return true;
    if(a.size()<b.size())
        return true;
    return false;
}
void merge(vector<string > &a,int l,int r){
    int m=(l+r)/2;
    vector<string > ls(m-l+1);
    vector<string > rs(r-m);
    for(int i=0;i<m-l+1;i++)
        ls[i]=a[l+i];
    for(int i=0;i<r-m;i++)
        rs[i]=a[m+1+i];
    int i=0,j=0,k=l;
    while(i<ls.size() && j<rs.size()){
        if(proverka(ls[i],rs[j]))
            a[k++]=ls[i++];
        
        else
            a[k++]=rs[j++];
            
    }
    while(i<ls.size())
        a[k++]=ls[i++];
        
    while(j<rs.size())
        a[k++]=rs[j++];
}
void merge_sort(vector<string > &a,int l,int r){
    if(l<r){
    merge_sort(a,l,(l+r)/2);
    merge_sort(a,(l+r)/2+1,r);
    merge(a,l,r);
}
}
int main(){
    int n;
    cin>>n;
    cin.ignore();
    string s;
    
    while(n--){
        vector<string > sss;
        getline(cin,s);
        stringstream ss(s);
        string w;
        while(ss>>w){
            sss.push_back(w);
        }
        merge_sort(sss,0,sss.size()-1);
        for(string i: sss){
            cout<<i<<' ';
        }
        cout<<endl;
    }
}