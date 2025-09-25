#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
 
void tez(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}
class Node{
    public:
    int data;
    Node *next;

    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};
class stq{
    public:
    Node *top;
    int sz;

    stq(){
        top=NULL;
        sz=0;
    }

    void push(int data){
        Node *node = new Node(data);
        node->next=top;
        top=node;
        sz++;
    }
    void pop(){
        if(top!=NULL){
            top=top->next;
            sz--;
        }
    }
    bool empty(){
        return sz==0;
    }
    int size(){
        return sz;
    }

};
int main(){
    tez();
    int n,k,pos=0;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    int c=1000000001;
    cin>>k;
    for(int i=0;i<n;i++){
        if(abs(a[i]-k)<c){
            c=abs(a[i]-k);
            pos=i;
        }
    }
    cout<<pos;
}