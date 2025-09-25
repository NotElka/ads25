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
    int n;
    string s;
    cin>>n>>s;
    queue<int> qk;
    queue<int> qs;
    for(int i=0;i<n;i++){
        if(s[i]=='K')
            qk.push(i);
        else   qs.push(i);
    }
    while(!qs.empty() and !qk.empty()){
        if(qk.front()<qs.front()){
            qs.pop();
            qk.push(qk.front()+n);
            qk.pop();
        }
        else{
            qk.pop();
            qs.push(qs.front()+n);
            qs.pop();
        }
    }
    if(qs.empty()) cout<<"KATSURAGI";
    else cout<<"SAKAYANAGI";
}