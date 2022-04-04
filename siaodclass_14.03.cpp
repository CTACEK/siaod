#include <iostream>

using namespace std;

const int n = 4, m = 4;

bool nullRow(int *r, int m) {
    for (int i = 0; i < m; i++) {
        if (r[i] == 0) {
            return true;
        }
    }
    return false;
}

void delRows(int x[][m], int &n, int m) {
    for (int i = 0; i < n; i++) {
        if (nullRow(x[i], m)) {
            for (int i1 = i; i1 < n - 1; i1++) {
                for (int j = 0; j < m; j++) {
                    x[i1][j] = x[i1 + 1][j];
                }
            }
            n--;
            i--;
        }
    }
}

void outputmass(int x[n][m], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << x[i][j] << ' ';
        }
        cout << endl;
    }
}

int main() {


    int x[n][m] = {{1, 2, 3, 7},
                   {0, 0, 0, 0},
                   {4, 5, 6, 8},
                   {0, 0, 0, 0}};

    int nx = n;


    delRows(x, nx, m);
    outputmass(x, nx, m);
    return 0;
}
