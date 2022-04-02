#include <iostream>
#include <vector>


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

int checkMersenN(vector<int> &x) {
    int m = 0;
    for (vector<int>::iterator i = x.begin(); i != x.end(); i++) {
        if (checkMersen(*i)) {
            m += 1;
        }
    }
    return m;
}

void findmindel(vector<int> &x) {
    bool flag = false;
    long long int min = 1000000000000;
    int min_i = -1;
    for (int i = 0; i < x.size(); i++) {
        if (x[i] < min && degreeoftwo(x[i])) {
            min_i = i;
            min = x[i];
        }
    }
    if (min_i > -1) {
        x.erase(x.begin() + min_i);
    }
}

void findmaxins(vector<int> &x, const int nw) {
    int max_i = -1;
    int max = -1;
    for (int i = 0; i < x.size(); i++) {
        if (x[i] > max && checkMersen(x[i])) {
            max_i = i;
            max = x[i];
        }
    }
    if (max_i > -1) {
        x.insert(x.begin() + max_i + 1, nw);
    }
}

void inputvector(vector<int> &x, int size) {
    cout << "Wedite " << size << " chisel\n";
    for (int i = 0; i < size; i++) {
        int temp;
        cin >> temp;
        x[i] = temp;
    }

}

void outputvector(vector<int> &x) {
    cout << "Massiv " << x.size() << " chisel\n";
    for (auto const &element: x) {
        cout << element << ' ';
    }
    cout << endl;
}

//void inputRandvector(int *x, int n) {
//    srand(time(0));
//    for (int i = 0; i < n; i++) {
//        x[i] = rand() % 100;
//    }
//}


int main() {
    int size = 8;
    vector<int> myVector(size);
    inputvector(myVector, size);
    outputvector(myVector);
    cout << "Zadanie 1.1 " << checkMersenN(myVector) << endl;
    cout << "Zadanie 1.2 " << endl;
    findmindel(myVector);
    outputvector(myVector);
    cout << "Zadanie 1.3 " << endl;
    findmaxins(myVector, 5555);
    outputvector(myVector);
    return 0;
}