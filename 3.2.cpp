#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;


vector<string> arrcreate(string str) {
    vector<string> temp;
    string s = "";
    for (int i = 0; i < str.length(); i++) {
        if (str[i] != ' ') {
            s = s + str[i];
        } else {
            if (s != "") {
                temp.push_back(s);
                s = "";
            }
        }
    }
    temp.push_back(s);
    return temp;
}


void outputvector(vector<string> &x) {
    for (auto const &element: x) {
        cout << element << ' ';
    }
    cout << endl;
}


vector<string> checkingallarray(vector<string> a) {
    vector<string> temp;
    for (int i = 0; i < a.size(); i++) { // проход по элементам массива
        for (int j = 0; j < a.size(); j++) {
            string temp1 = a[i];
            string temp2 = a[j];
            sort(temp1.begin(), temp1.end(), greater<>());
            sort(temp2.begin(), temp2.end(), greater<>());
            if (temp1 == temp2 && i != j) {
                temp.push_back(a[i]);
            }
        }
    }
    return temp;
}


int main() {
    setlocale(LC_ALL, "rus");;
    string str;

    getline(cin, str);
    vector<string> z = arrcreate(str);

    vector<string> result = checkingallarray(z);
    outputvector(result);
    return 0;
}