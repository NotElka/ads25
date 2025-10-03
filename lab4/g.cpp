#include<bits/stdc++.h>
#define ll long long
using namespace std;
class Node{
    public:
    ll data;
    Node* l;
    Node* r;
    Node(ll data){
        this->data=data;
        l=NULL;
        r=NULL;
    }
};
class tree{
    public:
    Node* root;
    tree(){
        root=NULL;
    }
    Node* insert(Node* node,ll data){
        if(node==NULL){
            return new Node(data);
            
        }
        if(node->data==data)
            return node;
        if(node->data>data)
            node->l=insert(node->l,data);
        else node->r=insert(node->r,data);
        return node;
    }
    ll find(Node* node,ll& a){
        if(node==NULL)
            return 0;
        ll lh=find(node->l,a);
        ll rh=find(node->r,a);
        a=max(a,lh+rh);
        return 1+max(lh,rh);

    }    
};
int main(){
    ll n,b;
    cin>>n;
    ll a=0;
    tree* t=new tree();
    for(ll i=0;i<n;i++){
        cin>>b;
        t->root=t->insert(t->root,b);
    }
    //cout<<t->root->l->l->data;
    t->find(t->root,a);
    cout<<a+1;
}