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
};
int solve(Node* node,int &a){
    if(node==NULL)
        return 0;
    a+=node->data+solve(node->r,a);
    cout<<a<<' ';
    return solve(node->l,a);
}
int main(){
    int n,a;
    cin>>n;
    tree* t=new tree();
    for(int i=0;i<n;i++){
        cin>>a;
        t->root=t->insert(t->root,a);
    }
    a=0;
    solve(t->root,a);
}