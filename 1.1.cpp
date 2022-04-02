#include "iostream"

using namespace std;
const int N = 1000;

bool degreeoftwo(int entered) {
    int temp = 1;
    while (temp < entered) {
        temp *= 2;
    }
    if (temp == entered) {
        return true;
    } else {
        return false;
    }
}

bool prost(int n) {
    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            return false;
        }
        return true;
    }
}
bool checkMersen(int x) {
    if (prost(x) && degreeoftwo(x + 1)) {
        return true;
    }
    return false;
}

int checkMersenN(int *x, int n) {
    int m = 0;
    for (int i = 0; i < n; i++) {
        if (checkMersen(x[i])) {
            m += 1;
        }
    }
    return m;
}


void findmindel(int *x, int &n) {
    bool flag = false;
    long long int min = 1000000000000;
    for (int i = 0; i < n; i++) {
        if (x[i] < min && degreeoftwo(x[i])) {
            min = i;
            flag = true;
        }
    }
    if (flag) {
        for (int i = min; i < n; i++) {
            x[i] = x[i + 1];
        }
        n--;
    }
}

void findmaxins(int *x, int &n, int nw) {
    int max = -1;
    for (int i = 0; i < n; i++) {
        if (x[i] > max && checkMersen(x[i])) {
            max = i;
        }
    }
    if (max > -1) {
        for (int i = n; i > max; i--) {
            x[i + 1] = x[i];
        }
        x[max + 1] = nw;
    }
    n++;
}

void inputarray(int *x, int n) {
    cout << "Wedite " << n << " chisel\n";
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

}

void outarray(int *x, int n) {
    cout << "Massiv " << n << " chisel\n";
    for (int i = 0; i < n; i++) {
        cout << x[i] << ' ';
    }
    cout << endl;
}

void inputRandarray(int *x, int n) {
    srand(time(0));
    for (int i = 0; i < n; i++) {
        x[i] = rand() % 100;
    }
}
//
//void erase(int *x, int &n, int pos) {
//    for (int i = pos; i < n - 1; i++) {
//        x[i] = x[i + 1];
//    }
//    n--;
//}
//
//void insert(int *x, int &n, int pos, int value) {
//    for (int i = n; i > pos; i--) {
//        x[i] = x[i - 1];
//    }
//    x[pos] = value;
//    n++;
//}
//
//void delchet(int *x, int &n) { //сделать линейную реализацию!!!
//    for (int i = 0; i < n; i++) {
//        if (x[i] % 2 == 0) {
//            erase(x, n, i);
//            i--;
//        }
//    }
//}

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    int a[N];
    int size = 8;
//    cout << "Vvedite size:";
//    cin >> size;
    int n = 32;
    cout << degreeoftwo(n) << endl;
    inputarray(a, size);
    outarray(a, size);
    cout << "Zadanie 1.1 " << checkMersenN(a, size) << endl;
    cout << "Zadanie 1.2 " << endl;
    findmindel(a, size);
    outarray(a, size);
    cout << "Zadanie 1.3 " << endl;
    findmaxins(a, size, 5555);
    outarray(a, size);
    return 0;
}