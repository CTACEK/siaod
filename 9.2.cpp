//
// Created by CTACEK on 5/16/2022.
//
#include <iostream>
#include <iomanip>
#include <string>


using namespace std;

string names[4] = {"Ryan Brown", "Davis Ostin", "Mark Mandel", "John Jobs"};
string numbers[4] = {"+7(936)209-93-10", "+7(981)942-26-08", "+7(941)802-26-23", "+7(970)767-98-51"};

int HashFunctionHorner(string &s, int table_size, const int key) {
    int hash_result = 0;
    for (int i = 0; s[i] != s.size(); ++i) {
        hash_result = (key * hash_result + s[i]) % table_size;
    }
    hash_result = (hash_result * 2 + 1) % table_size;
    return hash_result;
}

struct HashFunction1 {
    int operator()(string &s, int table_size) const {
        return HashFunctionHorner(s, table_size, table_size - 1);
    }
};

struct HashFunction2 {
    int operator()(string &s, int table_size) const {
        return HashFunctionHorner(s, table_size, table_size + 1);
    }
};

template<class THash1 = HashFunction1, class THash2 = HashFunction2>
class HashTable {
    static const int default_size = 4;
    constexpr static const double rehash_size = 0.75;

    struct User {
        string number;
        string address;
        bool state;

        User(string number_, string address_) : number(number_), state(true), address(address_) {}
    };

    User **arr;
    int size;
    int buffer_size;
    int size_all_non_nullptr;

    void resize() {
        int past_buffer_size = buffer_size;
        buffer_size *= 2;
        size_all_non_nullptr = 0;
        size = 0;
        User **arr2 = new User *[buffer_size];
        for (int i = 0; i < buffer_size; ++i)
            arr2[i] = nullptr;
        swap(arr, arr2);
        for (int i = 0; i < past_buffer_size; ++i) {
            if (arr2[i] && arr2[i]->state)
                add(arr2[i]->number, arr2[2]->address);
        }
        for (int i = 0; i < past_buffer_size; ++i)
            if (arr2[i])
                delete arr2[i];
        delete[] arr2;
    }

    void rehash() {
        size_all_non_nullptr = 0;
        size = 0;
        User **arr2 = new User *[buffer_size];
        for (int i = 0; i < buffer_size; ++i)
            arr2[i] = nullptr;
        swap(arr, arr2);
        for (int i = 0; i < buffer_size; ++i) {
            if (arr2[i] && arr2[i]->state)
                add(arr2[i]->number, arr2[i]->address);
        }
        for (int i = 0; i < buffer_size; ++i)
            if (arr2[i])
                delete arr2[i];
        delete[] arr2;
    }


public:
    HashTable() {
        buffer_size = default_size;
        size = 0;
        size_all_non_nullptr = 0;
        arr = new User *[buffer_size];
        for (int i = 0; i < buffer_size; ++i)
            arr[i] = nullptr;
    }

    ~HashTable() {
        for (int i = 0; i < buffer_size; ++i)
            if (arr[i])
                delete arr[i];
        delete[] arr;
    }

    bool add(string &key, string &address, const THash1 &hash1 = THash1(), const THash2 &hash2 = THash2()) {
        if (size + 1 > int(rehash_size * buffer_size))
            resize();
        else if (size_all_non_nullptr > 2 * size)
            rehash();
        int h1 = hash1(key, buffer_size);
        int h2 = hash2(key, buffer_size);
        int i = 0;
        int first_deleted = -1;
        while (arr[h1] != nullptr && i < buffer_size) {
            if (arr[h1]->number == key && arr[h1]->state)
                return false;
            if (!arr[h1]->state && first_deleted == -1)
                first_deleted = h1;
            h1 = (h1 + h2) % buffer_size;
            ++i;
        }
        if (first_deleted == -1) {
            arr[h1] = new User(key, address);
            ++size_all_non_nullptr;
        } else {
            arr[first_deleted]->number = key;
            arr[first_deleted]->state = true;
        }
        ++size;
        return true;
    }

    bool remove(string &value, const THash1 &hash1 = THash1(), const THash2 &hash2 = THash2()) {
        int h1 = hash1(value, buffer_size);
        int h2 = hash2(value, buffer_size);
        int i = 0;
        while (arr[h1] != nullptr && i < buffer_size) {
            if (arr[h1]->number == value && arr[h1]->state) {
                arr[h1]->state = false;
                arr[h1]->address = "";
                --size;
                return true;
            }
            h1 = (h1 + h2) % buffer_size;
            ++i;
        }
        return false;
    }

    string find(string &value, const THash1 &hash1 = THash1(), const THash2 &hash2 = THash2()) {
        int h1 = hash1(value, buffer_size);
        int h2 = hash2(value, buffer_size);
        int i = 0;
        while (arr[h1] != nullptr && i < buffer_size) {
            if (arr[h1]->number == value && arr[h1]->state)
                return arr[h1]->address;
            h1 = (h1 + h2) % buffer_size;
            ++i;
        }
        return "None";
    }
};


int main() {
    HashTable<HashFunction1,HashFunction2> hashTable;
    hashTable.add((string &) numbers[0], (string &) names[0]);
    hashTable.add((string &) numbers[1], (string &) names[1]);
    hashTable.remove((string &) numbers[0]);

    cout << hashTable.find((string&) numbers[0]) << endl;
    cout << hashTable.find((string&) numbers[1]);
    return 0;
}
