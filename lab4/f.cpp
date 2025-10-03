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
    Node* vstavit(Node* node,int data){
        if(node==NULL){
            Node* node=new Node(data);
            return node;
        }
        if(node->data>data)
            node->l=vstavit(node->l,data);
        else
            node->r=vstavit(node->r,data);
        return node;
        }
        int triangles(Node* node,int &cnt){
            if(node==NULL) return 0;
            if(node->l and node->r) cnt++;
            triangles(node->l,cnt);
            triangles(node->r,cnt);
            return cnt;
        }
};
int main(){
    int n,a;
    cin>>n;
    tree* b=new tree();
    for(int i=0;i<n;i++){
        cin>>a;
        b->root=b->vstavit(b->root,a);
    }
    int cnt=0;
    b->triangles(b->root,cnt);
    cout<<cnt;
}
