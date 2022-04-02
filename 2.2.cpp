#include <iostream>

using namespace std;


void outputmass(int **x, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << x[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
}

int **createmas(int n, int m) {
    int **A;
    A = new int *[n];
    for (int i = 0; i < n; i++) {
        A[i] = new int[m];
    }
    return A;
}

void deletemas(int **A, int n) {
    for (int i = 0; i < n; i++) {
        delete[] A[i];
    }
    delete[] A; // Освобождение памяти
}


void randomgenerate(int **x, int n, int m) {
    srand(time(0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            x[i][j] = rand() % 10;
        }
    }
}

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    int n, m;
    string track;
    cin >> n >> m;

    int **A = createmas(n, m);

    int **B = createmas(n, m);


    randomgenerate(A, n, m);
    outputmass(A, n, m);

    B[0][0] = A[0][0];

    for (int i = 1; i < n; i++) B[i][0] = B[i - 1][0] + A[i][0];
    for (int j = 1; j < m; j++) B[0][j] = B[0][j - 1] + A[0][j];

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            B[i][j] = min(B[i - 1][j], B[i][j - 1]) + A[i][j];
        }
    }

    int i = n - 1;
    int j = m - 1;

    while (i != 0 || j != 0) {
        track = " -> A[" + to_string(i + 1) + "][" + to_string(j + 1) + "]" + track;
        if (i == 0) j--;
        else if (j == 0) i--;
        else if (min(B[i - 1][j], B[i][j - 1]) >= B[i - 1][j]) i--;
        else j--;
    }

    track = "A[1][1]" + track;

//    outputmass(B, n, m);

    cout << track;

    deletemas(A, n);
    deletemas(B, n);

    return 0;
}

