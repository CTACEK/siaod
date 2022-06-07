#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>


using namespace std;

string marks[4] = {"Porsche", "Toyota", "Nissan", "Lexus"};

struct Auto {
    int number;
    string mark;
    string info;
};

struct AutoBook {
    int max_count_of_users = 0;

    Auto *Autos;

    AutoBook(int count);

    ~AutoBook();


    int find_auto(int number);

    int find_auto_barrier(int number);

    int find_auto_fib(int number);

    void create_random_table();

    bool comp(Auto auto1, Auto auto2);

};

AutoBook::AutoBook(int count) {
    max_count_of_users = count;
    Autos = new Auto[count];
}

AutoBook::~AutoBook() {
    delete[] Autos;
}

void AutoBook::create_random_table() {
    string words = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890";
    for (int i = 0; i < max_count_of_users; i++) {
        Autos[i].number = rand() % 1000000;
        Autos[i].mark = marks[rand() % 4];
        for (int j = 0; j < 10; j++) {
            Autos[i].info += words[rand() % 62];
        }
    }
}

int AutoBook::find_auto(int number) {
    for (int i = 0; i < max_count_of_users; i++) {
        if (Autos[i].number == number) {
            return i;
        }
    }
    return -1;
}

int AutoBook::find_auto_barrier(int number) {
    int size = max_count_of_users;
    if (size != 0) {
        int last = Autos[size - 1].number;
        Autos[size - 1].number = number;
        int i = 0;
        for (i = 0; Autos[i].number != number; ++i)
            Autos[size - 1].number = last;
        if (i != (size - 1) || number == last) return i;
    }
    return -1;
}

int AutoBook::find_auto_fib(int number) {
    int i = 1, p = 1, q = 0;
    int size = max_count_of_users;
    while (i < size) {
        q = p;
        p = i;
        i = p + q;
    }
    while (true) {
        if (i - 1 < size) {
            if (number < Autos[i - 1].number) {
                if (q == 0) {
                    return -1;
                }
                i = i - q;
                q = p - q;
                p = p - q;
            } else if (number > Autos[i - 1].number) {
                if (p == 1) {
                    return -1;
                }
                i = i + q;
                p = p - q;
                q = q - p;
            } else {
                return i - 1;
            }
        } else {
            if (q == 0) {
                return -1;
            }
            i = i - q;
            q = p - q;
            p = p - q;
        }
    }
}



int main() {
    int n;
    cin >> n;
    AutoBook autoBook(n);
    autoBook.create_random_table();

    int index = autoBook.Autos[rand() % n].number;

    cout << "Finding user with linear finding" << endl;
    auto begin1 = chrono::steady_clock::now();
    autoBook.find_auto(index);
    auto end1 = chrono::steady_clock::now();
    cout << "Time: " << chrono::duration_cast<chrono::microseconds>(end1 - begin1).count() << " mircosec"
         << endl;
    //cout << "Info: " << autoBook.Autos[res_lin].info << "\tMark: " << autoBook.Autos[res_lin].mark << endl;

    cout << endl;

    cout << "Finding user with barrier finding" << endl;
    auto begin2 = chrono::steady_clock::now();
    autoBook.find_auto_barrier(index);
    auto end2 = chrono::steady_clock::now();
    cout << "Time: " << chrono::duration_cast<chrono::microseconds>(end2 - begin2).count() << " mircosec"
         << endl;
    //cout << "Info: " << autoBook.Autos[res_bar].info << "\tMark: " << autoBook.Autos[res_bar].mark << endl;


    cout << endl;

    cout << "Finding user with fibonacci finding" << endl;

    sort(autoBook.Autos, autoBook.Autos + n,
         [](const Auto &p1, const Auto &p2) {
             return p1.number < p2.number; //сравнение
         });

    auto begin3 = chrono::steady_clock::now();
    autoBook.find_auto_fib(index);
    auto end3 = chrono::steady_clock::now();
    cout << "Time: " << chrono::duration_cast<chrono::microseconds>(end3 - begin3).count() << " mircosec" << endl;

    return 0;
}
