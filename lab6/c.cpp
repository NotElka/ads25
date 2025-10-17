#include<bits/stdc++.h>
using namespace std;
void insert(vector<int> &a,int x){
    int i=a.size();
    a.push_back(x);
    while(i>0 && a[i]<a[(i-1)/2]){
        swap(a[i],a[(i-1)/2]);
        i=(i-1)/2;
    }
}
void heapify(vector<int> &a,int i){
    if(2*i+1>=a.size()) return;
    int j=2*i+1;
    if(j+1<a.size() && a[j]>a[j+1])
        j++;
    if(a[i]>a[j])
        swap(a[i],a[j]);
        heapify(a,j);
}
int mh(vector<int> &a){
    int mn=a[0];
    swap(a[0],a[a.size()-1]);
    a.pop_back();
    heapify(a,0);
    return mn;
}
vector<int> hs(vector<int> &a){
    vector<int> h;
    for(int i=0;i<a.size();i++) 
        insert(h,a[i]);
    for(int i=0;i<a.size();i++)
        a[i]=mh(h);
    return a;
}
int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    a=hs(a);
    int mn=20000001;
    for(int i=1;i<n;i++) 
        mn=min(abs(a[i-1]-a[i]),mn);
    for(int i=1;i<n;i++){
        if(abs(a[i-1]-a[i])==mn)
            cout<<a[i-1]<<' '<<a[i]<<' ';
    }
}