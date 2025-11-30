#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> q;
    int choice, val;
    do {
        cout << "1 Push 2 Pop 3 Top 4 Exit\n";
        cin >> choice;
        if (choice == 1) {
            cin >> val; q.push(val);
            for (int i = 0; i < q.size() - 1; i++) { q.push(q.front()); q.pop(); }
        } else if (choice == 2) {
            if (!q.empty()) q.pop(); else cout << "Empty\n";
        } else if (choice == 3) {
            if (!q.empty()) cout << q.front() << "\n"; else cout << "Empty\n";
        }
    } while (choice != 4);
    return 0;
}