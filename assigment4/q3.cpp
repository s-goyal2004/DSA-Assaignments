#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n; cin >> n;
    queue<int> q;
    for (int i = 0; i < n; i++) { int x; cin >> x; q.push(x); }
    int half = n / 2;
    queue<int> fh;
    for (int i = 0; i < half; i++) { fh.push(q.front()); q.pop(); }
    while (!fh.empty()) { q.push(fh.front()); fh.pop(); q.push(q.front()); q.pop(); }
    while (!q.empty()) { cout << q.front() << " "; q.pop(); }
    cout << "\n";
    return 0;
}