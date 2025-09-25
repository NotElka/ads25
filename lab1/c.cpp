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
    stack<int> s;
    string a;
    cin>>a;
    for(int i=0;i<a.size();i++){
        if(a[i]=='#')
            s.pop();
        else
            s.push(a[i]);
    }
    stack<int> s1;
    cin>>a;
    for(int i=0;i<a.size();i++){
        if(a[i]=='#')
            s1.pop();
        else
            s1.push(a[i]);
    }
    if(s==s1)
        cout<<"Yes";
    else
        cout<<"No";
}