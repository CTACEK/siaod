#include <iostream>
#include <cstdlib>


using namespace std;

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

void addelem(int *&arr, int &size, const int value, int currid) {
    size++;
    arr = (int *) realloc(arr, sizeof(int) * (size));
    if (!arr) exit(1);
    for (int i = size - 1; i > currid; i--) {
        arr[i] = arr[i - 1];
    }
    arr[currid] = value;
}

void delelem(int *&arr, int &size, int id) {
    for (int i = id; i < size; i++) {
        arr[i] = arr[i + 1];
    }
    size--;
    arr = (int *) realloc(arr, sizeof(int) * size);
}

void findmindel(int *&x, int &n) {
    bool flag = false;
    long long int min = 1000000000000;
    for (int i = 0; i < n; i++) {
        if (x[i] < min && degreeoftwo(x[i])) {
            min = i;
            flag = true;
        }
    }
    if (flag) {
        delelem(x,n,min);
    }
}

void findmaxins(int *&x, int &n, int nw) {
    int max = -1;
    for (int i = 0; i < n; i++) {
        if (x[i] > max && checkMersen(x[i])) {
            max = i;
        }
    }
    if (max > -1) {
        addelem(x,n,nw,max + 1);
    }
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


int main() {
    int size = 8;
    int *dinarr = (int *) malloc(sizeof(int) * size);
    inputarray(dinarr, size);
    outarray(dinarr, size);
    cout << "Zadanie 1.1 " << checkMersenN(dinarr, size) << endl;
    cout << "Zadanie 1.2 " << endl;
    findmindel(dinarr, size);
    outarray(dinarr, size);
    cout << "Zadanie 1.3 " << endl;
    findmaxins(dinarr, size, 5555);
    outarray(dinarr,size);
    free(dinarr);
    dinarr = nullptr;
    return 0;
}
