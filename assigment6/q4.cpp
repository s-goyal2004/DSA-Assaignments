#include <iostream>
using namespace std;

struct DNode {
    char data;
    DNode* prev;
    DNode* next;
};

class DoublyLinkedList {
private:
    DNode* head;
public:
    DoublyLinkedList() : head(nullptr) {}

    void insertLast(char val) {
        DNode* n = new DNode{val, nullptr, nullptr};
        if (!head) { head = n; return; }
        DNode* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = n;
        n->prev = temp;
    }

    bool isPalindrome() {
        if (!head) return true;
        DNode* left = head;
        DNode* right = head;
        while (right->next) right = right->next;

        while (left != right && right->next != left) {
            if (left->data != right->data) return false;
            left = left->next;
            right = right->prev;
        }
        return true;
    }

    void display() {
        DNode* temp = head;
        while (temp) { cout << temp->data << " "; temp = temp->next; }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList dll;
    string s;
    cout << "Enter string/characters for Doubly Linked List: ";
    cin >> s;

    for (char c : s) dll.insertLast(c);

    cout << "Doubly Linked List: "; dll.display();
    if (dll.isPalindrome()) cout << "The list is a palindrome.\n";
    else cout << "The list is not a palindrome.\n";
}
