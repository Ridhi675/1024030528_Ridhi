#include <iostream>
using namespace std;

class Node {
public:
    char data;
    Node* prev;
    Node* next;
    Node(char val) { data = val; prev = next = NULL; }
};

class DoublyLinkedList {
    Node* head;
public:
    DoublyLinkedList() { head = NULL; }
    void insert(char val) {
        Node* newNode = new Node(val);
        if (!head) { head = newNode; return; }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }

    bool isPalindrome() {
        if (!head) return true;
        Node* left = head;
        Node* right = head;
        while (right->next) right = right->next;
        while (left != right && right->next != left) {
            if (left->data != right->data) return false;
            left = left->next;
            right = right->prev;
        }
        return true;
    }
};

int main() {
    DoublyLinkedList dll;
    string s;
    cout << "Enter string: ";
    cin >> s;
    for (char c : s) dll.insert(c);
    if (dll.isPalindrome())
        cout << "The linked list is Palindrome.\n";
    else
        cout << "The linked list is NOT Palindrome.\n";
    return 0;
}
