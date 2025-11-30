#include <iostream>
using namespace std;

// Linear Time Method
int findMissingLinear(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] != i + 1) {
            return i + 1;  // Missing number found
        }
    }
    return n; // If no mismatch, missing number is last
}

// Binary Search Method
int findMissingBinary(int arr[], int n) {
    int left = 0, right = n - 2; // because array size = n-1

    while (left <= right) {
        int mid = (left + right) / 2;

        if (arr[mid] == mid + 1) {
            left = mid + 1;  // Missing number is on right side
        } else {
            right = mid - 1; // Missing number is on left side
        }
    }
    return left + 1;
}

int main() {
    int arr[] = {1, 2, 3, 5, 6, 7, 8}; // Example: n=8, missing=4
    int n = 8;

    cout << "Missing Number (Linear): " << findMissingLinear(arr, n) << endl;
    cout << "Missing Number (Binary Search): " << findMissingBinary(arr, n) << endl;

    return 0;
}
