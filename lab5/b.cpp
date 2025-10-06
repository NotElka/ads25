#include<bits/stdc++.h>
using namespace std;
void insert(vector<int> &a,int x){
    a.push_back(x);
    int sz=a.size()-1;
    while(sz>0 && a[sz]>a[(sz-1)/2]){
        swap(a[sz],a[(sz-1)/2]);
        sz=(sz-1)/2;
    }
}
void heapify(vector<int> &a,int i){
    if(2*i+1>=a.size())
        return;
    int j=2*i+1;
    if(j+1<a.size() && a[j]<a[j+1])
        j++;
    if(a[j]>a[i]){
        swap(a[i],a[j]);
        heapify(a,j);
    }
}
int main(){
    int n,b;
    cin>>n;
    vector<int> a;
    for(int i=0;i<n;i++){
        cin>>b;
        insert(a,b);
    }
    while(a.size()>1){
        int f,s;
        f=a[0];
        swap(a[0],a[a.size()-1]);
        a.pop_back();
        heapify(a,0);
        s=a[0];
        swap(a[0],a[a.size()-1]);
        a.pop_back();
        heapify(a,0);
        if(f!=s)
            insert(a,abs(s-f));
    }
    if(a.size())
        cout<<a[0];
    else
        cout<<0;
}