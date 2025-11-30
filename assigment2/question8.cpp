#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    int arr[n];

    cout << "Enter elements:\n";
    for(int i = 0; i < n; i++) cin >> arr[i];

    // Sort the array
    sort(arr, arr + n);

    // Count distinct elements
    int count = 1; // first element is always distinct if n>0
    for(int i = 1; i < n; i++) {
        if(arr[i] != arr[i-1]) count++;
    }

    cout << "Total number of distinct elements: " << count << endl;

    return 0;
}
