 // frequency_count.cpp
 #include <bits/stdc++.h>
 using namespace std;
 int main() {
    vector<int> nums = {2,3,2,4,3,2};
 unordered_map<int,int> freq;
    for (int x : nums) freq[x]++;
    // Print in increasing key order for neatness:
    vector<int> keys;
    for (auto &p : freq) keys.push_back(p.first);
    sort(keys.begin(), keys.end());
    for (int k : keys) {
 cout << k << " -> " << freq[k] << (freq[k] == 1 ? " time\n" : " times\n");
    }
    return 0;
 }
