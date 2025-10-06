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
    ll q,k,x,sm=0;
    cin>>q>>k;
    string s;
    vector<ll> a;
    while(q--){
        cin>>s;
        if(s=="print"){
            cout<<sm<<endl;
        }
        else{
            cin>>x;
            if(a.size()<k){
                insert(a,x);
                sm+=x;
            }
            else if(a[0]<x){
                sm+=x-a[0];
                a[0]=x;
                heapify(a,0);
            }
        }
    }
}