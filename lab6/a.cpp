#include<bits/stdc++.h>
using namespace std;
bool c(char a,char b){
    char vowel[5]={'a','e','i','o','u'};
    if(*find(vowel,vowel+5,a) && *find(vowel,vowel+5,b))
        return a<b;
    if(*find(vowel,vowel+5,a))
        return true;
    if(*find(vowel,vowel+5,b))
        return false;
    return a<b;
}
int main(){
    int n;
    cin>>n;
    vector<char> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a.begin(),a.end(),c);
    for(int i=0;i<n;i++) cout<<a[i];
}