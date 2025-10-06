#include<bits/stdc++.h>
#define ll long long
using namespace std;
void insert(vector<ll> &a,ll x){
    a.push_back(x);
    ll sz=a.size()-1;
    while(sz>0 && a[sz]<a[(sz-1)/2]){
        swap(a[sz],a[(sz-1)/2]);
        sz=(sz-1)/2;
    }
}
void heapify(vector<ll> &a,ll i){
    if(2*i+1>=a.size())
        return;
    ll j=2*i+1;
    if(j+1<a.size() && a[j]>a[j+1])
        j++;
    if(a[j]<a[i]){
        swap(a[i],a[j]);
        heapify(a,j);
    }
}
int main(){
    ll n,m,x;
    cin>>n>>m;
    vector<ll> a;
    for(ll i=0;i<n;i++){
        cin>>x;
        insert(a,x);
    }
    ll ans=0;
    while(a.size()>1 && a[0]<m){
        ll d,ds;
        d=a[0];
        swap(a[0],a[a.size()-1]);
        a.pop_back();
        heapify(a,0);
        ds=a[0];
        swap(a[0],a[a.size()-1]);
        a.pop_back();
        heapify(a,0);
        insert(a,d+2*ds);
        ans++;
    }
    if(a[0]>=m)
        cout<<ans;
    else
        cout<<-1;
}