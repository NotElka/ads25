#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    ll n,k;
    cin>>n;
    priority_queue<ll,vector<ll>,greater<ll> > a;
    for(ll i=0;i<n;i++){
        cin>>k;
        a.push(k);
    }
    k=0;
    ll f,s;
    while(a.size()>1){
        f=a.top();
        a.pop();
        k+=f+a.top();
        a.push(f+a.top());
        a.pop();
    }
    cout<<k;
}