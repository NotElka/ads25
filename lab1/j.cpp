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
    deque<int> d;
    char s; int a;
    while(1){
        cin>>s;
        if(s=='!') break;
        else if(s=='*'){
            if(d.empty()) cout<<"error"<<endl;
            else{
                cout<<d.front()+d.back()<<endl;
                if(d.size()!=1)
                d.pop_back(); d.pop_front();
            }
        }
        else if(s=='+'){
            cin>>a;
            d.push_front(a);
        }
        else{
            cin>>a;
            d.push_back(a);
        }
    }
}