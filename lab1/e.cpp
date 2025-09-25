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
    int a;
    queue<int> b;
    queue<int> n;
    for(int i=0;i<5;i++){
        cin>>a;
        b.push(a);
    }
    for(int i=0;i<5;i++){
        cin>>a;
        n.push(a);
    }
    int i=0;
    while(i!=100000 and (!b.empty() and !n.empty())){
        i++;
        if((b.front()>n.front() or (b.front()==0 and n.front()==9)) and (b.front()!=9 or n.front()!=0)){
            //cout<<b.front()<<' '<<n.front()<<endl;
            b.push(b.front());
            b.push(n.front());
            b.pop(); n.pop();
        }
        else{
            n.push(b.front());
            n.push(n.front());
            b.pop(); n.pop();
        }
    }
    if(b.empty()){
        cout<<"Nursik "<<i;
    }
    else if(n.empty()){
        cout<<"Boris "<<i;
    }
    else cout<<"blin nichya";
}