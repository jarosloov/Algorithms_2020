#include <iostream>

using namespace std;

//void matrix_multiplication() {}

int main() {
    int N = 2;
    int A[2][2];
    int B[2][2];
    int C[2][2];
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            A[i][j] = rand() % 10;
            B[i][j] = rand() % 10;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            C[i][j] = 0;
            for (int k = 0; k < N; k++)
                C[i][j] += A[i][k] * B[k][j];
        }
    }
    cout << "matrix A" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << A[i][j] << ' ';
        }
        cout << endl;
    }

    cout << "matrix B" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << B[i][j] << ' ';
        }
        cout << endl;
    }

    cout << "matrix C" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << C[i][j] << ' ';
        }
        cout << endl;
    }
       
    return 0;
}

// Jarosloov //
