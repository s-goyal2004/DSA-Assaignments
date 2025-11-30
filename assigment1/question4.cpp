#include <iostream>
using namespace std;

class Operations {
public:
    // Reverse an array
    void reverseArray() {
        int n, arr[100];
        cout << "Enter size of array: ";
        cin >> n;

        cout << "Enter elements: ";
        for (int i = 0; i < n; i++) cin >> arr[i];

        for (int i = 0, j = n - 1; i < j; i++, j--) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }

        cout << "Reversed array: ";
        for (int i = 0; i < n; i++) cout << arr[i] << " ";
        cout << endl;
    }

    // Matrix multiplication
    void matrixMultiplication() {
        int m, n, p;
        cout << "Enter rows and cols of first matrix (m n): ";
        cin >> m >> n;
        cout << "Enter cols of second matrix (p): ";
        cin >> p;

        int A[50][50], B[50][50], C[50][50] = {0};

        cout << "Enter elements of first matrix (" << m << "x" << n << "):\n";
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                cin >> A[i][j];

        cout << "Enter elements of second matrix (" << n << "x" << p << "):\n";
        for (int i = 0; i < n; i++)
            for (int j = 0; j < p; j++)
                cin >> B[i][j];

        // multiplication
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < p; j++) {
                C[i][j] = 0;
                for (int k = 0; k < n; k++) {
                    C[i][j] += A[i][k] * B[k][j];
                }
            }
        }

        cout << "Resultant Matrix (" << m << "x" << p << "):\n";
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < p; j++) {
                cout << C[i][j] << " ";
            }
            cout << endl;
        }
    }

    // Transpose of a matrix
    void transposeMatrix() {
        int m, n, A[50][50], T[50][50];
        cout << "Enter rows and cols of matrix: ";
        cin >> m >> n;

        cout << "Enter elements of matrix (" << m << "x" << n << "):\n";
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                cin >> A[i][j];

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                T[j][i] = A[i][j];
            }
        }

        cout << "Transpose Matrix (" << n << "x" << m << "):\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << T[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Operations op;
    int choice;

    do {
        cout << "\n-- MENU --\n";
        cout << "1. Reverse Array\n";
        cout << "2. Matrix Multiplication\n";
        cout << "3. Transpose of Matrix\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: op.reverseArray(); break;
            case 2: op.matrixMultiplication(); break;
            case 3: op.transposeMatrix(); break;
            case 4: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 4);

    return 0;
}
