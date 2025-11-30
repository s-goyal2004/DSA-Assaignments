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

void findMiddle() {
    Node* slow = head;
    Node* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    if (slow) cout << slow->data << "\n";
}

int main() {
    int n, val;
    cin >> n;
    for (int i = 0; i < n; i++) { cin >> val; insertEnd(val); }
    findMiddle();
    return 0;
}