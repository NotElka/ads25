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
    vector<ll> p(1000001,1);
    p[1]=0;
    for(ll i=2;i*i<1000001;i++){
        if(p[i]){
            for(ll j=i*i;j<1000001;j+=i)
                p[j]=0;
        }
    }
    if(p[n])
        cout<<"YES";
    else
        cout<<"NO";
}