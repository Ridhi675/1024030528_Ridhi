#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) { data = val; next = NULL; }
};

class LinkedList {
public:
    Node* head;
    LinkedList() { head = NULL; }

    void insert(int val) {
        Node* newNode = new Node(val);
        if (!head) { head = newNode; return; }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }

    bool isCircular() {
        if (!head) return false;
        Node* temp = head->next;
        while (temp && temp != head)
            temp = temp->next;
        return (temp == head);
    }
};

int main() {
    LinkedList list;
    list.insert(10);
    list.insert(20);
    list.insert(30);

    // Uncomment below to make it circular manually:
    // list.head->next->next->next = list.head;

    if (list.isCircular())
        cout << "Linked List is Circular.\n";
    else
        cout << "Linked List is NOT Circular.\n";
    return 0;
}
