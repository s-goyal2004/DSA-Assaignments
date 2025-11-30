#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> q1, q2;
    int choice, val;
    do {
        cout << "1 Push 2 Pop 3 Top 4 Exit\n";
        cin >> choice;
        if (choice == 1) { cin >> val; q1.push(val); }
        else if (choice == 2) {
            if (q1.empty()) cout << "Empty\n"; else {
                while (q1.size() > 1) { q2.push(q1.front()); q1.pop(); }
                q1.pop(); swap(q1, q2);
            }
        } else if (choice == 3) {
            if (q1.empty()) cout << "Empty\n"; else {
                while (q1.size() > 1) { q2.push(q1.front()); q1.pop(); }
                cout << q1.front() << "\n"; q2.push(q1.front()); q1.pop(); swap(q1, q2);
            }
        }
    } while (choice != 4);
    return 0;
}