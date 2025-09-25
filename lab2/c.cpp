#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node *prev;
    Node(int data) {
        this->data = data;
        next = prev = NULL;
    }
};

class llist {
public:
    Node *head, *tail;
    llist() {
        head = NULL;
        tail = NULL;
    }
    void pb(int data) {
        Node *node = new Node(data);
        if (tail == NULL) {
            tail = head = node;
        } else {
            node->prev = tail;
            tail->next = node;
            tail = node;
        }
    }
    void pf(int data) {
        Node *node = new Node(data);
        if (head == NULL) {
            head = tail = node;
        } else {
            node->next = head;
            head->prev = node;
            head = node;
        }
    }
    void pop_back() {
        if (tail != NULL) {
            tail = tail->prev;
            if (tail != NULL) {
                tail->next = NULL;
            } else
                head = NULL;
        }
    }
    void pop_front() {
        if (head != NULL) {
            head = head->next;
            if (head != NULL)
                head->prev = NULL;
            else
                tail = NULL;
        }
    }
    void del_node(Node *node) {
        if (node == tail)
            pop_back();
        else if (node == head)
            pop_front();
        else {
            Node *a = node->prev;
            Node *b = node->next;
            a->next = b;
            b->prev = a;
        }
    }

    void print() {
        Node *node = head;
        while (node != NULL) {
            cout << node->data << " ";
            node = node->next;
        }
        cout << endl;
    }
};

int main() {
    int n;
    cin >> n;
    int b;
    llist* ll = new llist();
    for (int i = 0; i < n; i++) {
        cin >> b;
        ll->pb(b);
    }
    Node *h = ll->head;
    int idx = 0;
    while (h != NULL) {
        Node *next = h->next;
        if (idx % 2 == 1) {
            ll->del_node(h);
        }
        h = next;
        idx++;
    }
    ll->print();
}