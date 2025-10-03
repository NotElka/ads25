#include<bits/stdc++.h>
using namespace std;
struct Node {
	pair<int,int> data;
	Node* left;
	Node* right;

	Node(int data) {
		this->data = make_pair(data,1);
		left = NULL;
		right = NULL;
	} 
};

Node* getMin(Node* root) {
	while (root->left != NULL) {
		root = root->left;
	}
	return root;
}

Node* add(Node* root, int data) {
	if (root == NULL)
		return new Node(data);
    if(root->data.first==data){
        root->data.second++;
        return root;
    }
	 else if (root->data.first > data) {
		if (root->left == NULL) {
			root->left = new Node(data);
		} else {
			root->left = add(root->left, data);
		}
	} else if (root->data.first < data) {
		if (root->right == NULL) {
			root->right = new Node(data);
		} else {
			root->right = add(root->right, data);
		}
	}
	return root;
}

Node* deleteNode(Node* root, int data) {
	if (root == NULL) {
		return NULL;
	} else if (root->data.first > data) {
		root->left = deleteNode(root->left, data);
		return root;
	} else if (root->data.first < data) {
		root->right = deleteNode(root->right, data);
		return root;
	} else {
        if(root->data.second){
            root->data.second--;
            return root;}
        else{
		if (root->left == NULL && root->right == NULL) {
			delete root;
			return NULL;
		} else if (root->right == NULL) {
			Node* temp = root->left;
			delete root;
			return temp;
		} else if (root->left == NULL) {
			Node* temp = root->right;
			delete root;
			return temp;
		} else {
			Node* temp = getMin(root->right);
			root->data = temp->data;
			root->right = deleteNode(root->right, temp->data.first);
			return root;
		}}
	}
}

Node* find(Node* root, int x) {
	if (root == NULL) {
		return NULL;
	} else if (root->data.first == x) {
		return root;
	} else if (root->data.first < x) {
		return find(root->right, x);
	} else {
		return find(root->left, x);
	}
}

int main(){
    int q,a;
    cin>>q;
    string s;
    Node* root=NULL;
    while(q--){
        cin>>s>>a;
        if(s=="insert")
            root=add(root,a);
        else if(s=="cnt"){
            Node* node=find(root,a);
			if(node==NULL) cout<<0<<'\n';
			else
            cout<<node->data.second<<'\n';
        }
        else   
            root=deleteNode(root,a);
    }

}