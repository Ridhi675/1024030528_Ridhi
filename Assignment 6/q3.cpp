#include <iostream>
using namespace std;

class DNode {
public:
    int data;
    DNode* next;
    DNode* prev;
    DNode(int val) { data = val; next = prev = NULL; }
};

class DoublyLinkedList {
    DNode* head;
public:
    DoublyLinkedList() { head = NULL; }
    void insert(int val) {
        DNode* newNode = new DNode(val);
        if (!head) { head = newNode; return; }
        DNode* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }
    int getSize() {
        int count = 0; DNode* temp = head;
        while (temp) { count++; temp = temp->next; }
        return count;
    }
};

class CNode {
public:
    int data;
    CNode* next;
    CNode(int val) { data = val; next = NULL; }
};

class CircularLinkedList {
    CNode* head;
public:
    CircularLinkedList() { head = NULL; }
    void insert(int val) {
        CNode* newNode = new CNode(val);
        if (!head) { head = newNode; newNode->next = head; return; }
        CNode* temp = head;
        while (temp->next != head) temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
    }
    int getSize() {
        if (!head) return 0;
        int count = 0;
        CNode* temp = head;
        do { count++; temp = temp->next; } while (temp != head);
        return count;
    }
};

int main() {
    DoublyLinkedList dll;
    CircularLinkedList cll;
    dll.insert(1); dll.insert(2); dll.insert(3);
    cll.insert(10); cll.insert(20); cll.insert(30);
    cout << "Size of Doubly Linked List: " << dll.getSize() << endl;
    cout << "Size of Circular Linked List: " << cll.getSize() << endl;
    return 0;
}
