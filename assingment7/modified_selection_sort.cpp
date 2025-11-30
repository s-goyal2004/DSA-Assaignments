#include <iostream>
#include <vector>
using namespace std;

void improvedSelectionSort(vector<int>& arr) {
    int left = 0;
    int right = arr.size() - 1;

    while (left < right) {
        int minIndex = left;
        int maxIndex = right;

        // If the elements at ends are inverted, fix them
        if (arr[minIndex] > arr[maxIndex]) {
            swap(arr[minIndex], arr[maxIndex]);
        }

        // Find min and max in the remaining part
        for (int i = left + 1; i < right; i++) {
            if (arr[i] < arr[minIndex])
                minIndex = i;
            else if (arr[i] > arr[maxIndex])
                maxIndex = i;
        }

        // Place minimum at beginning
        swap(arr[left], arr[minIndex]);

        // If max element was moved because it was at left
        if (maxIndex == left)
            maxIndex = minIndex;

        // Place maximum at end
        swap(arr[right], arr[maxIndex]);

        left++;
        right--;
    }
}

int main() {
    int n;
    cout << "Enter size of vector: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    improvedSelectionSort(arr);

    cout << "Sorted vector: ";
    for (int x : arr)
        cout << x << " ";

    return 0;
}
