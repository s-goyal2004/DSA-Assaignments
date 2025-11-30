#include <iostream>
using namespace std;

int main() {
    const int SIZE = 5;
    int arr[SIZE];
    int front = 0, rear = -1, count = 0;
    int choice, val;
    do {
        cout << "1 Enq 2 Deq 3 Peek 4 Display 5 Exit\n";
        cin >> choice;
        if (choice == 1) {
            cin >> val;
            if (count == SIZE) cout << "Full\n";
            else { rear = (rear + 1) % SIZE; arr[rear] = val; count++; }
        } else if (choice == 2) {
            if (count == 0) cout << "Empty\n";
            else { cout << arr[front] << "\n"; front = (front + 1) % SIZE; count--; }
        } else if (choice == 3) {
            if (count == 0) cout << "Empty\n"; else cout << arr[front] << "\n";
        } else if (choice == 4) {
            if (count == 0) cout << "Empty\n"; else { int i = front; for (int c = 0; c < count; c++) { cout << arr[i] << " "; i = (i + 1) % SIZE; } cout << "\n"; }
        }
    } while (choice != 5);
    return 0;
}