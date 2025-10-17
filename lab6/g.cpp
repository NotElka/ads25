#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    string a,b;
    map<string, string> m1;
    map<string, string> m2;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        if(m2.count(a)){
            m1[m2[a]]=b;
            m2[b]=m2[a];
        }
        else{
        m1[a]=b;
        m2[b]=a;}
    }
    cout<<m1.size()<<endl;
    for(auto it : m1)
        cout<<it.first<<' '<<it.second<<endl;
}