#include <iostream>
using namespace std;

struct CNode {
    int data;
    CNode* next;
};

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

    void display() {
        if (!head) return;
        CNode* temp = head;
        do { cout << temp->data << " "; temp = temp->next; } while (temp != head);
        cout << endl;
    }

    bool isCircular() {
        if (!head) return false;
        CNode* temp = head->next;
        while (temp && temp != head) temp = temp->next;
        return temp == head;
    }
};

int main() {
    CircularLinkedList cll;
    int n, val;
    cout << "Enter number of nodes: ";
    cin >> n;
    cout << "Enter values: ";
    for (int i = 0; i < n; i++) { cin >> val; cll.insertLast(val); }

    cout << "Circular Linked List: "; cll.display();

    if (cll.isCircular()) cout << "The list is circular.\n";
    else cout << "The list is not circular.\n";
}
