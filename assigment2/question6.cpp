#include <iostream>
using namespace std;

struct Triplet {
    int row;
    int col;
    int val;
};

// Function to display a sparse matrix
void displaySparse(Triplet t[], int size) {
    cout << "Row  Column  Value\n";
    for (int i = 0; i < size; i++) {
        cout << t[i].row << "      " << t[i].col << "      " << t[i].val << endl;
    }
}

// (a) Transpose of a sparse matrix
void transposeSparse(Triplet t[], int size) {
    Triplet trans[size];
    for (int i = 0; i < size; i++) {
        trans[i].row = t[i].col;
        trans[i].col = t[i].row;
        trans[i].val = t[i].val;
    }
    cout << "\nTransposed Sparse Matrix:\n";
    displaySparse(trans, size);
}

// (b) Addition of two sparse matrices
void addSparse(Triplet A[], int sizeA, Triplet B[], int sizeB) {
    Triplet sum[sizeA + sizeB];
    int i = 0, j = 0, k = 0;

    while (i < sizeA && j < sizeB) {
        if (A[i].row < B[j].row || (A[i].row == B[j].row && A[i].col < B[j].col)) {
            sum[k++] = A[i++];
        } else if (A[i].row > B[j].row || (A[i].row == B[j].row && A[i].col > B[j].col)) {
            sum[k++] = B[j++];
        } else {
            // Same position
            sum[k] = A[i];
            sum[k].val += B[j].val;
            i++; j++;
            if (sum[k].val != 0) k++;
        }
    }

    while (i < sizeA) sum[k++] = A[i++];
    while (j < sizeB) sum[k++] = B[j++];

    cout << "\nSum of Sparse Matrices:\n";
    displaySparse(sum, k);
}

// (c) Multiplication of two sparse matrices
void multiplySparse(Triplet A[], int sizeA, int rA, int cA, Triplet B[], int sizeB, int rB, int cB) {
    if (cA != rB) {
        cout << "Matrix multiplication not possible.\n";
        return;
    }

    int result[rA][cB] = {0};

    // Convert A and B to normal 2D arrays temporarily
    for (int i = 0; i < sizeA; i++) result[A[i].row][A[i].col] += A[i].val;
    int Bmat[rB][cB] = {0};
    for (int i = 0; i < sizeB; i++) Bmat[B[i].row][B[i].col] = B[i].val;

    // Multiply
    for (int i = 0; i < rA; i++)
        for (int j = 0; j < cB; j++)
            for (int k = 0; k < cA; k++)
                result[i][j] += result[i][k] * Bmat[k][j];

    // Convert back to triplet
    Triplet resTriplet[rA*cB];
    int count = 0;
    for (int i = 0; i < rA; i++)
        for (int j = 0; j < cB; j++)
            if (result[i][j] != 0) {
                resTriplet[count].row = i;
                resTriplet[count].col = j;
                resTriplet[count].val = result[i][j];
                count++;
            }

    cout << "\nProduct of Sparse Matrices (Triplet Form):\n";
    displaySparse(resTriplet, count);
}

int main() {
    int choice;

    do {
        cout << "\n--- Sparse Matrix Operations Menu ---\n";
        cout << "1. Transpose\n2. Addition\n3. Multiplication\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int n, rows, cols;
                cout << "Enter number of non-zero elements: ";
                cin >> n;
                Triplet t[n];
                cout << "Enter row, column, value for each element:\n";
                for (int i = 0; i < n; i++) cin >> t[i].row >> t[i].col >> t[i].val;
                transposeSparse(t, n);
                break;
            }

            case 2: {
                int nA, nB;
                cout << "Enter number of non-zero elements in Matrix A: ";
                cin >> nA;
                Triplet A[nA];
                cout << "Enter row, column, value for each element of A:\n";
                for (int i = 0; i < nA; i++) cin >> A[i].row >> A[i].col >> A[i].val;

                cout << "Enter number of non-zero elements in Matrix B: ";
                cin >> nB;
                Triplet B[nB];
                cout << "Enter row, column, value for each element of B:\n";
                for (int i = 0; i < nB; i++) cin >> B[i].row >> B[i].col >> B[i].val;

                addSparse(A, nA, B, nB);
                break;
            }

            case 3: {
                int nA, nB, rA, cA, rB, cB;
                cout << "Enter rows and cols of Matrix A: ";
                cin >> rA >> cA;
                cout << "Enter number of non-zero elements in A: ";
                cin >> nA;
                Triplet A[nA];
                cout << "Enter row, column, value for each element of A:\n";
                for (int i = 0; i < nA; i++) cin >> A[i].row >> A[i].col >> A[i].val;

                cout << "Enter rows and cols of Matrix B: ";
                cin >> rB >> cB;
                cout << "Enter number of non-zero elements in B: ";
                cin >> nB;
                Triplet B[nB];
                cout << "Enter row, column, value for each element of B:\n";
                for (int i = 0; i < nB; i++) cin >> B[i].row >> B[i].col >> B[i].val;

                multiplySparse(A, nA, rA, cA, B, nB, rB, cB);
                break;
            }

            case 4: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }

    } while(choice != 4);

    return 0;
}
