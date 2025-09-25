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
    string s;
    cin>>s;
    stack<char> a;
    a.push('1');
    for(int i=0;i<s.size();i++){
        if(a.top()==s[i])
            a.pop();
        else
            a.push(s[i]);
    }
    if(a.top()=='1')
        cout<<"YES";
    else  cout<<"NO";
}