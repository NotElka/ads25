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
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        deque<int> d;
        for(int i=n;i>0;i--){
            d.push_front(i);
            for(int j=0;j<i;j++){
                d.push_front(d.back());
                d.pop_back();
            }
        }
        for(int i=0;i<n;i++){
            cout<<d[i]<<' ';
        }
        cout<<endl;
    }
}