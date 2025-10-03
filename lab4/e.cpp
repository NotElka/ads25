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
    Node* naidi(Node* node,int data){
        if(node==NULL) return NULL;
        if(node->data==data) 
            return node;
        Node *left=naidi(node->l,data);
        if(left) return left;
        return naidi(node->r,data);
    }
    Node* insert(Node* node,int data1,int data2,int side){
        if(node==NULL){
            Node *node=new Node(data2);
            return node;
        }
        Node *parent=naidi(node,data1);
        if(!parent) return node;
        if(side) parent->r=new Node(data2);
        else parent->l=new Node(data2);
        return node;
    }
    int height(Node *node){
        if(node==NULL) return 0;
        return 1+max(height(node->l),height(node->r));
    }
    void dfs(Node *node,vector<int>& a,int h=0){
        if(node==NULL) 
            return;
        a[h]+=1;
        dfs(node->l,a,h+1);
        dfs(node->r,a,h+1);
        return;
    }
    /*Node* naidi(Node* node,int data){
        if(node==NULL || node->data==data)
            return node;
        if(node->data>data)
            naidi(node->l,data);
        else
            naidi(node->r,data);
    }*/
};
int main(){
    int n,x,y,z;
    cin>>n;
    tree *t=new tree();
    t->root=t->insert(t->root,1,1,1);
    for(int i=1;i<n;i++){
        cin>>x>>y>>z;
        t->root=t->insert(t->root,x,y,z);
    }
    vector<int> otv(t->height(t->root)); 
    int mx=0;
    t->dfs(t->root,otv);
    for(int i=0;i<otv.size();i++) mx=max(mx,otv[i]);
    cout<<mx;
}