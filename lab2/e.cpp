#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s,s1;
    vector<string> a(1);
    cin>>a[0];
    s1=a[0];
    for(int i=1;i<n;i++){
        cin>>s;
        if(s!=s1) {a.push_back(s); s1=s;}
    }
    reverse(a.begin(),a.end());
    cout<<"All in all: "<<a.size()<<endl<<"Students:"<<endl;
    for(int i=0;i<a.size();i++){
        cout<<a[i]<<endl;
    }
}