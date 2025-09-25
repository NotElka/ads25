#include <iostream>
using namespace std;

class Node {
public:
    string data;
    Node *next, *prev;

    Node(string data) {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

class LinkedList {
public:
    Node *tail, *front;

    LinkedList() {
        tail = NULL;
        front = NULL;
    }

    void push_back(string data) {
        Node *node = new Node(data);
        if (tail == NULL) {
            tail = node;
            front = node;
        } else {
            node->prev = tail;
            tail->next = node;
            tail = node;
        }
    }

    void push_front(string data) {
        Node *node = new Node(data);
        if (front == NULL) {
            tail = node;
            front = node;
        } else {
            front->prev = node;
            node->next = front;
            front = node;
        }
    }

    string pop_back() {
        if (tail == NULL) return "error";
        string s = tail->data;
        Node* to_delete = tail;
        tail = tail->prev;
        if (tail != NULL)
            tail->next = NULL;
        else
            front = NULL;
        delete to_delete;
        return s;
    }

    string pop_front() {
        if (front == NULL) return "error";
        string s = front->data;
        Node* to_delete = front;
        front = front->next;
        if (front != NULL)
            front->prev = NULL;
        else
            tail = NULL;
        delete to_delete;
        return s;
    }

    void del_node(Node *node) {
        if (node == tail)
            pop_back();
        else if (node == front)
            pop_front();
        else {
            Node *a = node->prev;
            Node *b = node->next;
            a->next = b;
            b->prev = a;
            delete node;
        }
    }

    string clear() {
        while (front) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
        tail = NULL;
        return "ok";
    }

    void print() {
        Node *node = front;
        while (node != NULL) {
            cout << node->data << " ";
            node = node->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList* a = new LinkedList();
    string s;
    while (cin >> s) {
        if (s == "add_front") {
            string b;
            cin >> b;
            a->push_front(b);
            cout << "ok" << endl;
        }
        else if (s == "add_back") {
            string b;
            cin >> b;
            a->push_back(b);
            cout << "ok" << endl;
        }
        else if (s == "erase_front") {
            string res = a->pop_front();
            if (res == "error") cout << "error" << endl;
            else cout << res << endl;
        }
        else if (s == "erase_back") {
            string res = a->pop_back();
            if (res == "error") cout << "error" << endl;
            else cout << res << endl;
        }
        else if (s == "front") {
            if (a->front == NULL) cout << "error" << endl;
            else cout << a->front->data << endl;
        }
        else if (s == "back") {
            if (a->tail == NULL) cout << "error" << endl;
            else cout << a->tail->data << endl;
        }
        else if (s == "clear") {
            cout << a->clear() << endl;
        }
        else if (s == "exit") {
            cout << "goodbye" << endl;
            break;
        }
    }
}