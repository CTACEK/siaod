//
// Created by CTACEK on 6/4/2022.
//
#include <iostream>
#include <unordered_map>


using namespace std;

typedef unordered_map<char, int> HashMap;

class HashTable {

public:
    unordered_map<char, int> hashtable;
    string pattern_s;

    HashTable(string pattern_s) {
        this->pattern_s = pattern_s;
        string base = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890";
        for (int i = 0; i < base.length(); i++) {
            hashtable[base[i]] = pattern_s.length();
        }
        for (int i = 0; i < pattern_s.length() - 1; i++) {
            hashtable[pattern_s[i]] = pattern_s.length() - i - 1;
            //cout << pattern_s[i] << "\t" << pattern_s.length() - i - 1 << endl;
        }
    }

    void PrintMap() {
        for (HashMap::const_iterator it = hashtable.begin(); it != hashtable.end(); ++it)
            cout << " [" << it->first << ", " << it->second << "]" << endl;
    }
};

int GetCountEntry(string t_string, HashTable hashtable1) {
    if (t_string.length() < hashtable1.pattern_s.length()) {
        return 0;
    }
    int size_p = hashtable1.pattern_s.length();
    int counter = 0;

    int i = size_p - 1;
    int j = 0;
    int k = 0;

    while (i < t_string.length()) {
        if (t_string[i] == hashtable1.pattern_s[size_p-1]) {
            k = size_p - 1;
            j = i;
            while (k > 0) {
                if (t_string[j] == hashtable1.pattern_s[k]) {
                    k--;
                    j--;
                } else {
                    i++;
                    break;
                }
            }
            if (k == 0) {
                i++;
                counter++;
            }
        } else {
            i += hashtable1.hashtable[t_string[i]];
        }
    }
    return counter;
}


int main() {
    string abc = "12abc12scascabc12scas12";
    HashTable hashTable("c12");
    cout << GetCountEntry(abc, hashTable);
    return 0;
}
