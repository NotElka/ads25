
#include<bits/stdc++.h>
using namespace std;

void qs(vector<char> &a,int l,int r){
    int p=a[(l+r)/2];
    int i=l;
    int j=r;
    while(i<j){
        while(p>a[i]) i++;
        while(p<a[j]) j--;
        if(i<=j){
            swap(a[i],a[j]);
            i++;
            j--;
        }
    }
    if(l<j)
        qs(a,l,j);
    if(i<r)
        qs(a,i,r);
}
int main(){
    vector<char> a;
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++) a.push_back(s[i]);
    qs(a,0,s.size()-1);
    for(int i=0;i<s.size();i++)
        cout<<a[i];
}