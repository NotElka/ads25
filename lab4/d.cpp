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
    Node* insert(Node* node,int data){
        if(node==NULL){
            node=new Node(data);
            return node;}
        if(node->data>=data)
            node->l=insert(node->l,data);
        else node->r=insert(node->r,data);
        return node;
    }
    int height(Node *node){
        if(node==NULL) return 0;
        return 1+max(height(node->l),height(node->r));
    }
    void dfs(Node *node,vector<int>& a,int h=0){
        vector<int > used(5001,0);
        if(node==NULL) return;
        a[h]+=node->data;
        if(used[node->data]==0){
            dfs(node->l,a,h+1);
            dfs(node->r,a,h+1);
        }
        return;
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
    vector<int> otv(t->height(t->root)); 
    cout<<t->height(t->root);
    t->dfs(t->root,otv);
    cout<<endl;
    for(int i=0;i<otv.size();i++){
        cout<<otv[i]<<' ';
    }
}