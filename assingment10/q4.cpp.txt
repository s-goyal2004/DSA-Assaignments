// first_non_repeating.cpp
#include <bits/stdc++.h>
using namespace std;

int firstNonRepeating(const vector<int>& a) {
    unordered_map<int,int> cnt;
    for (int x : a) cnt[x]++;
    for (int x : a) if (cnt[x] == 1) return x;
    return INT_MIN; // indicates no non-repeating element
}

int main() {
    vector<int> a = {4,5,1,2,0,4};
    int ans = firstNonRepeating(a);
    if (ans == INT_MIN) cout << "No non-repeating element\n";
    else cout << ans << "\n";
    return 0;
}
