#include <iostream>
#include <cstdlib>
using namespace std;

/*==================== Doubly Linked List ====================*/
class DNode {
public:
    int data;
    DNode *prev, *next;
    DNode(int val) {
        data = val;
        prev = next = NULL;
    }
};

class DoublyLinkedList {
    DNode* head;
public:
    DoublyLinkedList() { head = NULL; }

    void insertAtBegin(int val) {
        DNode* newNode = new DNode(val);
        if (!head) { head = newNode; return; }
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    void insertAtEnd(int val) {
        DNode* newNode = new DNode(val);
        if (!head) { head = newNode; return; }
        DNode* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }

    void insertAfter(int key, int val) {
        DNode* temp = head;
        while (temp && temp->data != key) temp = temp->next;
        if (!temp) { cout << "Node not found!\n"; return; }
        DNode* newNode = new DNode(val);
        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next) temp->next->prev = newNode;
        temp->next = newNode;
    }

    void deleteNode(int key) {
        DNode* temp = head;
        while (temp && temp->data != key) temp = temp->next;
        if (!temp) { cout << "Node not found!\n"; return; }
        if (temp->prev) temp->prev->next = temp->next;
        else head = temp->next;
        if (temp->next) temp->next->prev = temp->prev;
        delete temp;
        cout << "Node deleted.\n";
    }

    void search(int key) {
        DNode* temp = head;
        int pos = 1;
        while (temp) {
            if (temp->data == key) {
                cout << "Node " << key << " found at position " << pos << endl;
                return;
            }
            pos++; temp = temp->next;
        }
        cout << "Node not found!\n";
    }

    void display() {
        DNode* temp = head;
        cout << "Doubly Linked List: ";
        while (temp) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

/*==================== Circular Linked List ====================*/
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

    void insertAtEnd(int val) {
        CNode* newNode = new CNode(val);
        if (!head) { head = newNode; newNode->next = head; return; }
        CNode* temp = head;
        while (temp->next != head) temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
    }

    void deleteNode(int key) {
        if (!head) return;
        CNode* curr = head; CNode* prev = NULL;
        do {
            if (curr->data == key) {
                if (prev) prev->next = curr->next;
                else {
                    CNode* last = head;
                    while (last->next != head) last = last->next;
                    head = head->next;
                    last->next = head;
                }
                delete curr;
                cout << "Node deleted.\n";
                return;
            }
            prev = curr;
            curr = curr->next;
        } while (curr != head);
        cout << "Node not found.\n";
    }

    void search(int key) {
        if (!head) { cout << "List empty!\n"; return; }
        CNode* temp = head;
        do {
            if (temp->data == key) { cout << "Node found.\n"; return; }
            temp = temp->next;
        } while (temp != head);
        cout << "Node not found.\n";
    }

    void display() {
        if (!head) { cout << "List empty!\n"; return; }
        CNode* temp = head;
        cout << "Circular List: ";
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << head->data << endl;
    }
};

/*==================== Main Menu ====================*/
int main() {
    DoublyLinkedList dll;
    CircularLinkedList cll;
    int choice, val, key, type;

    while (true) {
        cout << "\n1. Doubly Linked List\n2. Circular Linked List\n3. Exit\nEnter type: ";
        cin >> type;
        if (type == 1) {
            cout << "\n--- Doubly Linked List ---\n";
            cout << "1.Insert at Begin  2.Insert at End  3.Insert After  4.Delete  5.Search  6.Display  7.Back\n";
            cout << "Enter choice: "; cin >> choice;
            switch (choice) {
                case 1: cout << "Enter value: "; cin >> val; dll.insertAtBegin(val); break;
                case 2: cout << "Enter value: "; cin >> val; dll.insertAtEnd(val); break;
                case 3: cout << "Enter key and value: "; cin >> key >> val; dll.insertAfter(key,val); break;
                case 4: cout << "Enter key: "; cin >> key; dll.deleteNode(key); break;
                case 5: cout << "Enter key: "; cin >> key; dll.search(key); break;
                case 6: dll.display(); break;
                default: break;
            }
        } else if (type == 2) {
            cout << "\n--- Circular Linked List ---\n";
            cout << "1.Insert at End  2.Delete  3.Search  4.Display  5.Back\n";
            cout << "Enter choice: "; cin >> choice;
            switch (choice) {
                case 1: cout << "Enter value: "; cin >> val; cll.insertAtEnd(val); break;
                case 2: cout << "Enter key: "; cin >> key; cll.deleteNode(key); break;
                case 3: cout << "Enter key: "; cin >> key; cll.search(key); break;
                case 4: cll.display(); break;
                default: break;
            }
        } else break;
    }
    return 0;
}
