#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) { data = val; next = NULL; }
};

class CircularLinkedList {
    Node* head;
public:
    CircularLinkedList() { head = NULL; }

    void insert(int val) {
        Node* newNode = new Node(val);
        if (!head) { head = newNode; newNode->next = head; return; }
        Node* temp = head;
        while (temp->next != head) temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
    }

    void display() {
        if (!head) { cout << "List empty!\n"; return; }
        Node* temp = head;
        cout << "Circular List: ";
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << head->data << endl;
    }
};

int main() {
    CircularLinkedList cll;
    cll.insert(20);
    cll.insert(100);
    cll.insert(40);
    cll.insert(80);
    cll.insert(60);
    cll.display();
    return 0;
}
