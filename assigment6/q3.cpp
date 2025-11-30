#include <iostream>
using namespace std;

// Doubly Linked List Node
struct DNode {
    int data;
    DNode* prev;
    DNode* next;
};

// Doubly Linked List
class DoublyLinkedList {
private:
    DNode* head;
public:
    DoublyLinkedList() : head(nullptr) {}

    void insertLast(int val) {
        DNode* n = new DNode{val, nullptr, nullptr};
        if (!head) { head = n; return; }
        DNode* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = n;
        n->prev = temp;
    }

    int size() {
        int count = 0;
        DNode* temp = head;
        while (temp) { count++; temp = temp->next; }
        return count;
    }

    void display() {
        DNode* temp = head;
        while (temp) { cout << temp->data << " "; temp = temp->next; }
        cout << endl;
    }
};

// Circular Linked List Node
struct CNode {
    int data;
    CNode* next;
};

// Circular Linked List
class CircularLinkedList {
private:
    CNode* head;
public:
    CircularLinkedList() : head(nullptr) {}

    void insertLast(int val) {
        CNode* n = new CNode{val, nullptr};
        if (!head) { head = n; n->next = head; return; }
        CNode* temp = head;
        while (temp->next != head) temp = temp->next;
        temp->next = n;
        n->next = head;
    }

    int size() {
        if (!head) return 0;
        int count = 0;
        CNode* temp = head;
        do { count++; temp = temp->next; } while (temp != head);
        return count;
    }

    void display() {
        if (!head) return;
        CNode* temp = head;
        do { cout << temp->data << " "; temp = temp->next; } while (temp != head);
        cout << endl;
    }
};

int main() {
    DoublyLinkedList dll;
    CircularLinkedList cll;
    int n, val;

    cout << "Enter number of nodes for Doubly Linked List: ";
    cin >> n;
    cout << "Enter values: ";
    for (int i = 0; i < n; i++) { cin >> val; dll.insertLast(val); }

    cout << "Doubly Linked List: "; dll.display();
    cout << "Size = " << dll.size() << endl;

    cout << "\nEnter number of nodes for Circular Linked List: ";
    cin >> n;
    cout << "Enter values: ";
    for (int i = 0; i < n; i++) { cin >> val; cll.insertLast(val); }

    cout << "Circular Linked List: "; cll.display();
    cout << "Size = " << cll.size() << endl;
}
