#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* l;
    Node* r;
    Node(int data){
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
    Node* insert(Node* node, int data){
        if(node==NULL){
            node=new Node(data);
            return node;
        }
        if(data<=node->data){
            node->l=insert(node->l,data);
        }
        else{
            node->r=insert(node->r,data);
        }
        return node;
    }
    int sz(Node* node){
        if(node==NULL) return 0;
        else{
            return 1+sz(node->l)+sz(node->r);
        }
    }
    void in_order(Node *node){
        if(node==NULL) return;
        cout<<node->data<<' ';
        in_order(node->l);
        in_order(node->r);
    }
    Node *naidi(Node *node,int d){
        if(node==NULL or node->data==d){
            in_order(node);
            return node;}
        if(node->data>d)
            return naidi(node->l,d);
        else
            return naidi(node->r,d);
    }
};
int main(){
    int n,a;
    cin>>n;
    tree *t=new tree();
    for(int i=0;i<n;i++){
        cin>>a;
        t->root=t->insert(t->root,a);
    }
    cin>>a;
    t->naidi(t->root,a);
}