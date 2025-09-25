#include<bits/stdc++.h>
using namespace std;
struct Node{
    int val;
    Node* next;
    Node(): val(0), next(nullptr) {}
    Node(int x): val(x), next(nullptr) {}
    Node(Node* next): val(0), next(next) {}
    Node(int x, Node* next): val(x), next(next) {}
};

Node* insert(Node* head, Node* node, int p){
    if(p==0){
        node->next=head;
        return node;
    }
    Node* curr=head;
    for(int i=0;i<p-1 && curr;i++){
        curr=curr->next;
    }
    node->next=curr->next;
    curr->next=node;
    return node;
}
 
Node* remove(Node* head, int p){
    if(!head) return nullptr;
    if(p==0){
        Node* temp=head;
        head=head->next;
        delete temp;
        return head;
    }
    Node* curr=head;
    for(int i=0;curr && i<p-1;i++){
        curr=curr->next;
    }
    if(curr && curr->next){
        Node* temp=curr->next;
        curr->next=temp->next;
        delete temp;
    }
    return head;
}
 
Node* replace(Node* head, int p1, int p2){
    int m=min(p1,p2);
    p2=max(p1,p2);
    p1=m;
    Node* node1=head;
    for(int i=0;i<p1;i++){
        node1=node1->next;
    }
    Node* next1=node1->next;
    Node* node2=node1;
    for(int i=p1;i<p2;i++){
        node2=node2->next;
    }
    node1->next=node2->next;
    node2->next=next1;
    return head;
}
 
Node* reverse(Node* head){
    Node* prev = nullptr;
    Node* curr = head;
    while (curr) {
        Node* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
}
 
void print(Node* head){
    if (!head) {
        cout << -1 << endl;
        return;
    }
    Node* curr = head;
    while (curr) {
        cout << curr->val;
        if (curr->next) cout << " ";
        curr = curr->next;
    }
    cout << endl;
}
 
Node* cyclic_left(Node* head, int x){
    if (!head || !head->next) return head;

    int len = 0;
    Node* tail = head;
    while (tail->next) {
        tail = tail->next;
        len++;
    }
    len++;

    x = x % len;
    if (x == 0) return head;

    tail->next = head;

    Node* newTail = head;
    for (int i = 0; i < x - 1; i++) {
        newTail = newTail->next;
    }
    Node* newHead = newTail->next;
    newTail->next = nullptr;

    return newHead;
}
 
Node* cyclic_right(Node* head, int x){
    if (!head || !head->next) return head;

    int len = 0;
    Node* tail = head;
    while (tail->next) {
        tail = tail->next;
        len++;
    }
    len++;

    x = x % len;
    if (x == 0) return head;

    int leftShift = len - x;

    tail->next = head;

    Node* newTail = head;
    for (int i = 0; i < leftShift - 1; i++) {
        newTail = newTail->next;
    }
    Node* newHead = newTail->next;
    newTail->next = nullptr;

    return newHead;
}
 
int main(){
    Node* head = nullptr;
    while (true)
    {
        int command; cin >> command;
        if (command == 0){
            break;
        }else if(command == 1){
            int x, p; cin >> x >> p;
            head = insert(head, new Node(x), p);
        }else if (command == 2){
            int p; cin >> p;
            head = remove(head, p);
        }else if (command == 3){
            print(head);
        }else if (command == 4){
            int p1, p2; cin >> p1 >> p2;
            head = replace(head, p1, p2);
        }else if (command == 5){
            head = reverse(head);
        }else if (command == 6){
            int x; cin >> x;
            head = cyclic_left(head, x);
        }else if (command == 7){
            int x; cin >> x;
            head = cyclic_right(head, x);
        }   
    }
    return 0;
}
