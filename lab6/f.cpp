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
void qs(vector<pair<string, double> > &a,int l,int r){
    int p=(l+r)/2;
    int i=l,j=r;
    while(i<j){
        while(a[i].second<a[p].second){ if(a[i].second==a[p].second && a[i].first>a[p].first) break;  i++;}
        while(a[j].second>a[p].second) {if(a[j].second==a[p].second && a[j].first<a[p].first) break; j--;}
        if(i<=j){
            swap(a[i],a[j]);
            i++;
            j--;}
    }
    if(j>l) qs(a,l,j);
    if(i<r) qs(a,i,r);
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
    sort(g.begin(),g.end(),comp);
    for(int i=0;i<n;i++)
        cout<<g[i].first<<' '<<fixed<<setprecision(3)<<g[i].second<<endl;
    
}