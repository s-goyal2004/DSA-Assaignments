#include <iostream>
using namespace std;

// 1. Diagonal Matrix
void diagonalMatrix() {
    int n;
    cout << "Enter size of diagonal matrix: ";
    cin >> n;
    int D[n];

    cout << "Enter diagonal elements:\n";
    for (int i = 0; i < n; i++) cin >> D[i];

    cout << "Full Diagonal Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) cout << D[i] << " ";
            else cout << 0 << " ";
        }
        cout << endl;
    }
}

// 2. Tri-diagonal Matrix
void triDiagonalMatrix() {
    int n;
    cout << "Enter size of tri-diagonal matrix: ";
    cin >> n;
    int T[3*n-2];

    cout << "Enter lower diagonal elements (n-1 elements):\n";
    for(int i = 1; i < n; i++) cin >> T[i-1];

    cout << "Enter main diagonal elements (n elements):\n";
    for(int i = 0; i < n; i++) cin >> T[n-1 + i];

    cout << "Enter upper diagonal elements (n-1 elements):\n";
    for(int i = 0; i < n-1; i++) cin >> T[2*n-1 + i];

    cout << "Full Tri-diagonal Matrix:\n";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i-j == 1) cout << T[i-1] << " ";
            else if(i == j) cout << T[n-1 + i] << " ";
            else if(j-i == 1) cout << T[2*n-1 + i] << " ";
            else cout << 0 << " ";
        }
        cout << endl;
    }
}

// 3. Lower Triangular Matrix
void lowerTriangularMatrix() {
    int n;
    cout << "Enter size of lower triangular matrix: ";
    cin >> n;
    int LT[n*(n+1)/2];

    cout << "Enter lower triangular elements row-wise:\n";
    for(int i = 0; i < n; i++)
        for(int j = 0; j <= i; j++)
            cin >> LT[i*(i+1)/2 + j];

    cout << "Full Lower Triangular Matrix:\n";
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i >= j) cout << LT[i*(i+1)/2 + j] << " ";
            else cout << 0 << " ";
        }
        cout << endl;
    }
}

// 4. Upper Triangular Matrix
void upperTriangularMatrix() {
    int n;
    cout << "Enter size of upper triangular matrix: ";
    cin >> n;
    int UT[n*(n+1)/2];

    cout << "Enter upper triangular elements row-wise:\n";
    for(int i = 0; i < n; i++)
        for(int j = i; j < n; j++)
            cin >> UT[i*n - i*(i-1)/2 + (j-i)];

    cout << "Full Upper Triangular Matrix:\n";
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i <= j) cout << UT[i*n - i*(i-1)/2 + (j-i)] << " ";
            else cout << 0 << " ";
        }
        cout << endl;
    }
}

// 5. Symmetric Matrix
void symmetricMatrix() {
    int n;
    cout << "Enter size of symmetric matrix: ";
    cin >> n;
    int S[n*(n+1)/2]; // store lower triangle

    cout << "Enter lower triangular elements row-wise:\n";
    for(int i = 0; i < n; i++)
        for(int j = 0; j <= i; j++)
            cin >> S[i*(i+1)/2 + j];

    cout << "Full Symmetric Matrix:\n";
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i >= j) cout << S[i*(i+1)/2 + j] << " ";
            else cout << S[j*(j+1)/2 + i] << " "; // symmetric
        }
        cout << endl;
    }
}

int main() {
    int choice;
    do {
        cout << "\n--- Efficient Matrix Storage Menu ---\n";
        cout << "1. Diagonal Matrix\n";
        cout << "2. Tri-diagonal Matrix\n";
        cout << "3. Lower Triangular Matrix\n";
        cout << "4. Upper Triangular Matrix\n";
        cout << "5. Symmetric Matrix\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1: diagonalMatrix(); break;
            case 2: triDiagonalMatrix(); break;
            case 3: lowerTriangularMatrix(); break;
            case 4: upperTriangularMatrix(); break;
            case 5: symmetricMatrix(); break;
            case 6: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice! Try again.\n";
        }
    } while(choice != 6);

    return 0;
}
