#include <iostream>
using namespace std;

int main() {
    const int SIZE = 5;
    int arr[SIZE];
    int front = -1, rear = -1;
    int choice, val;
    do {
        cout << "1 Enq 2 Deq 3 Peek 4 Display 5 Exit\n";
        cin >> choice;
        if (choice == 1) {
            cin >> val;
            if (rear == SIZE - 1) cout << "Full\n";
            else {
                if (front == -1) front = 0;
                arr[++rear] = val;
            }
        } else if (choice == 2) {
            if (front == -1) cout << "Empty\n";
            else {
                cout << arr[front] << "\n";
                if (front == rear) front = rear = -1; else front++;
            }
        } else if (choice == 3) {
            if (front == -1) cout << "Empty\n"; else cout << arr[front] << "\n";
        } else if (choice == 4) {
            if (front == -1) cout << "Empty\n"; else { for (int i = front; i <= rear; i++) cout << arr[i] << " "; cout << "\n"; }
        }
    } while (choice != 5);
    return 0;
}