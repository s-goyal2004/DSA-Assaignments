 // common_elements.cpp
 #include <bits/stdc++.h>
 using namespace std;
 vector<int> commonElements(const vector<int>& A, const vector<int>& B) {
 unordered_set<int> sa(A.begin(), A.end());
 unordered_set<int> res;
    for (int x : B) if (sa.count(x)) res.insert(x);
    return vector<int>(res.begin(), res.end());
 }
 int main() {
    vector<int> A = {1,2,3,4}, B = {3,4,5,6};
    auto c = commonElements(A, B);
    sort(c.begin(), c.end());
    for (size_t i = 0; i < c.size(); ++i) {
        if (i) cout << ", ";
 cout << c[i];
    }
 cout << "\n";
    return 0;
 }
