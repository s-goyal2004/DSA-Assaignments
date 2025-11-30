#include <iostream>
using namespace std;

#define MAX 100

class ArrayOperations {
    int arr[MAX];
    int size;

public:
    ArrayOperations() {
        size = 0;
    }

    // CREATE
    void create() {
        cout << "Enter number of elements: ";
        cin >> size;
        cout << "Enter elements:\n";
        for (int i = 0; i < size; i++) {
            cin >> arr[i];
        }
    }

    // DISPLAY
    void display() {
        if (size == 0) {
            cout << "Array is empty!\n";
            return;
        }
        cout << "Array elements are: ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // INSERT
    void insert() {
        int pos, val;
        if (size == MAX) {
            cout << "Array is full!\n";
            return;
        }
        cout << "Enter position (1-" << size+1 << "): ";
        cin >> pos;
        cout << "Enter value to insert: ";
        cin >> val;

        if (pos < 1 || pos > size + 1) {
            cout << "Invalid position!\n";
            return;
        }
        for (int i = size; i >= pos; i--) {
            arr[i] = arr[i - 1];
        }
        arr[pos - 1] = val;
        size++;
        cout << "Element inserted.\n";
    }

    // DELETE
    void Delete() {
        int pos;
        if (size == 0) {
            cout << "Array is empty!\n";
            return;
        }
        cout << "Enter position (1-" << size << "): ";
        cin >> pos;
        if (pos < 1 || pos > size) {
            cout << "Invalid position!\n";
            return;
        }
        for (int i = pos - 1; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        size--;
        cout << "Element deleted.\n";
    }

    // LINEAR SEARCH
    void linearSearch() {
        int key, flag = 0;
        cout << "Enter element to search: ";
        cin >> key;
        for (int i = 0; i < size; i++) {
            if (arr[i] == key) {
                cout << "Element found at position " << (i + 1) << endl;
                flag = 1;
                break;
            }
        }
        if (!flag) {
            cout << "Element not found!\n";
        }
    }
};

int main() {
    ArrayOperations obj;
    int choice;

    do {
        cout << "\n--MENU--\n";
        cout << "1.CREATE\n2.DISPLAY\n3.INSERT\n4.DELETE\n5.LINEAR SEARCH\n6.EXIT\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: obj.create(); break;
        case 2: obj.display(); break;
        case 3: obj.insert(); break;
        case 4: obj.Delete(); break;
        case 5: obj.linearSearch(); break;
        case 6: cout << "Exiting...\n"; break;
        default: cout << "Invalid choice!\n";
        }
    } while (choice != 6);

    return 0;
}
