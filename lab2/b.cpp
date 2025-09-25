#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int val){
        data=val;
        next=NULL;
    }
};
int main(){
    int n,k;
    cin>>n>>k;
    queue<string> q;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        q.push(s);
    }
    for(int i=0;i<k;i++){
        string s=q.front();
        q.pop();
        q.push(s);
    }
    for(int i=0;i<n;i++){
        cout<<q.front()<<" ";
        q.pop();
    }
}