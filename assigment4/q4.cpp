#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() {
    string s; cin >> s;
    queue<char> q;
    int freq[26] = {0};
    for (char c : s) {
        freq[c - 'a']++;
        q.push(c);
        while (!q.empty() && freq[q.front() - 'a'] > 1) q.pop();
        if (q.empty()) cout << -1 << " "; else cout << q.front() << " ";
    }
    cout << "\n";
    return 0;
}