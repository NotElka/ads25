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
        cin>>n;
        stack<int> s;
        s.push(-1);
        int a;
        for(int i=0;i<n;i++){
            cin>>a;
            while(a<s.top())
                s.pop();
            cout<<s.top()<<' ';
            s.push(a);
        }
        
}