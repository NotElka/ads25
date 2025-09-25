#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
 
void tez(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}
int main(){
    tez();
    ll n;
    cin>>n;
    vector<ll> p(10001,1);
    vector<ll> pp;
    p[1]=0;
    for(ll i=2;i*i<10001;i++){
        if(p[i]){
            for(ll j=i*i;j<10001;j+=i){
                p[j]=0;
            }
        }
    }
    int s=0;
    for(int i=2;i<p.size();i++){
        if(p[i]){
            s+=1;
            if(p[s])
                pp.pb(i);}
    }
    cout<<pp[n-1];
}