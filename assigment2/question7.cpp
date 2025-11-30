#include <iostream>
using namespace std;

int countInversionsBrute(int arr[], int n) {
    int count = 0;
    for(int i = 0; i < n-1; i++)
        for(int j = i+1; j < n; j++)
            if(arr[i] > arr[j])
                count++;
    return count;
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements:\n";
    for(int i = 0; i < n; i++) cin >> arr[i];

    int inversions = countInversionsBrute(arr, n);
    cout << "Number of inversions: " << inversions << endl;

    return 0;
}
