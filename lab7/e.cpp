#include<bits/stdc++.h>
using namespace std;
bool comp(pair<string , double> a, pair<string , double> b){
    if(a.second==b.second){
        if(a.first<=b.first) return true;
        return false;
    }
    if(a.second<b.second)
        return true;
    return false;
}
void merge(vector<pair<string,double> > &a,int l,int r){
    int m=(l+r)/2;
    vector<pair<string,double> > ls(m-l+1);
    vector<pair<string,double> > rs(r-m);
    for(int i=0;i<m-l+1;i++)
        ls[i]=a[l+i];
    for(int i=0;i<r-m;i++)
        rs[i]=a[m+1+i];
    int i=0,j=0;
    while(i<ls.size() && j<rs.size()){
        if(comp(ls[i],rs[j])){
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
void merge_sort(vector<pair<string,double> > &a,int l,int r){
    if(l<r){
    merge_sort(a,l,(l+r)/2);
    merge_sort(a,(l+r)/2+1,r);
    merge(a,l,r);
}
}
int main(){
    int n,m,a,c;
    cin>>n;
    string s;
    vector<pair<string, double> > g(n);
    for(int i=0;i<n;i++){
        cin>>s;
        g[i].first+=s+' ';
        cin>>s;
        g[i].first+=s;
        cin>>m;
        c=0;
        g[i].second=0;
        while(m--){
            cin>>s;
            cin>>a;
            c+=a;
            if(s=="A+")
                g[i].second+=4*a;
            else if(s=="A")
                g[i].second+=3.75*a;
            else if(s=="B+")
                g[i].second+=3.5*a;
            else if(s=="B")
                g[i].second+=3*a;
            else if(s=="C+")
                g[i].second+=2.5*a;
            else if(s=="C")
                g[i].second+=2*a;
            else if(s=="D+")
                g[i].second+=1.5*a;
            else if(s=="D")
                g[i].second+=1*a;
            else
                g[i].second+=0;
        }
        g[i].second=g[i].second/c;
    }
    merge_sort(g,0,n-1);
    for(int i=0;i<n;i++)
        cout<<g[i].first<<' '<<fixed<<setprecision(3)<<g[i].second<<endl;
    
}