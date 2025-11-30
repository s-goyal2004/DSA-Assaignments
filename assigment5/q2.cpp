#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = nullptr;

void insertEnd(int val) {
    Node* newNode = new Node{val, nullptr};
    if (!head) head = newNode;
    else {
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }
}

int deleteKey(int key) {
    int count = 0;
    while (head && head->data == key) {
        Node* temp = head;
        head = head->next;
        delete temp;
        count++;
    }
    Node* curr = head;
    while (curr && curr->next) {
        if (curr->next->data == key) {
            Node* del = curr->next;
            curr->next = del->next;
            delete del;
            count++;
        } else curr = curr->next;
    }
    return count;
}

void display() {
    Node* temp = head;
    while (temp) { cout << temp->data << " "; temp = temp->next; }
    cout << "\n";
}

int main() {
    int n, val, key;
    cin >> n;
    for (int i = 0; i < n; i++) { cin >> val; insertEnd(val); }
    cin >> key;
    int c = deleteKey(key);
    cout << "Count: " << c << "\n";
    display();
    return 0;
}