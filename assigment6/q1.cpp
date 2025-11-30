#include <iostream>
using namespace std;

struct DNode {
    int data;
    DNode *prev, *next;
};

class DoublyLinkedList {
private:
    DNode* head;
public:
    DoublyLinkedList() : head(nullptr) {}

    void insertFirst(int val) {
        DNode* n = new DNode{val, nullptr, head};
        if (head) head->prev = n;
        head = n;
    }

    void insertLast(int val) {
        DNode* n = new DNode{val, nullptr, nullptr};
        if (!head) { head = n; return; }
        DNode* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = n;
        n->prev = temp;
    }

    void insertAfter(int key, int val) {
        DNode* temp = head;
        while (temp && temp->data != key) temp = temp->next;
        if (!temp) { cout << "Node not found.\n"; return; }
        DNode* n = new DNode{val, temp, temp->next};
        if (temp->next) temp->next->prev = n;
        temp->next = n;
    }

    void insertBefore(int key, int val) {
        if (!head) return;
        if (head->data == key) { insertFirst(val); return; }
        DNode* temp = head;
        while (temp && temp->data != key) temp = temp->next;
        if (!temp) { cout << "Node not found.\n"; return; }
        DNode* n = new DNode{val, temp->prev, temp};
        temp->prev->next = n;
        temp->prev = n;
    }

    void deleteNode(int key) {
        if (!head) return;
        DNode* temp = head;
        while (temp && temp->data != key) temp = temp->next;
        if (!temp) { cout << "Node not found.\n"; return; }
        if (temp->prev) temp->prev->next = temp->next;
        else head = temp->next;
        if (temp->next) temp->next->prev = temp->prev;
        delete temp;
    }

    void search(int key) {
        DNode* temp = head;
        int pos = 1;
        while (temp) {
            if (temp->data == key) { cout << "Node found at position " << pos << endl; return; }
            temp = temp->next; pos++;
        }
        cout << "Node not found.\n";
    }

    void display() {
        DNode* temp = head;
        while (temp) { cout << temp->data << " "; temp = temp->next; }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList dll;
    int choice, val, key;

    while (true) {
        cout << "\n1.Insert 2.Delete 3.Search 4.Display 0.Exit: ";
        cin >> choice;
        if (choice == 0) break;
        switch(choice) {
            case 1:
                cout << "Value: "; cin >> val;
                cout << "1.First 2.Last 3.After 4.Before: "; cin >> key;
                if(key==1) dll.insertFirst(val);
                else if(key==2) dll.insertLast(val);
                else if(key==3) { cout << "After which node? "; cin >> key; dll.insertAfter(key,val); }
                else if(key==4) { cout << "Before which node? "; cin >> key; dll.insertBefore(key,val); }
                break;
            case 2: cout << "Delete value: "; cin >> val; dll.deleteNode(val); break;
            case 3: cout << "Search value: "; cin >> val; dll.search(val); break;
            case 4: dll.display(); break;
        }
    }
}
