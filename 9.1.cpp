//
// Created by CTACEK on 5/16/2022.
//
#include <iostream>
#include <iomanip>
#include <string>

//orders = (Order *) calloc(maxcountoforder, sizeof(Order));
//orders = (Order *) realloc(orders, countoforders * sizeof(Order));

using namespace std;

string names[4] = {"Ryan Brown", "Davis Ostin", "Mark Mandel", "John Jobs"};
string numbers[4] = {"+7(936)209-93-10", "+7(981)942-26-08", "+7(941)802-26-23", "+7(970)767-98-51"};

struct User {
    string number;
    string address;

    User(string number, string address);
};

struct PhoneBook {
    int count_of_users = 1;
    User Users[4];

    void add_user(User);

    void print_phonebook();

    void create_randomtable();

    string find_user(string number);

    string find_user_barier(string number);

};


void PhoneBook::print_phonebook() {
    cout << "Table of users of phonebook" << "      \n";
    cout << "__________________________________________\n";
    cout << left << setw(20) << "Number of user";
    cout << "|";
    cout << left << setw(20) << "Data of user";
    cout << "|" << endl;
    cout << "____________________|____________________|" << endl;
    for (User user: Users) {
        cout << left << setw(20) << user.number;
        cout << "|";
        cout << left << setw(20) << user.address;
        cout << "|" << endl;
        cout << "____________________|____________________|" << endl;
    }
}

void PhoneBook::create_randomtable() {
    int k = 0;
    for (User user: Users) {
        user.number = numbers[k];
        user.address = names[k];
        k++;
    }
}

string PhoneBook::find_user(string number) {
    for (User user: Users) {
        if (user.number == number) return user.address;
    }
}

string PhoneBook::find_user_barier(string number) {
    int size = count_of_users;
    if (size != 0) {
        string last = Users[size - 1].address;
        Users[size - 1].address = number;
        int i;
        for (i = 0; Users[i].address != number; ++i)
            Users[size - 1].address = last;
        if (i != (size - 1) || number == last) return Users[i].address;
    }
    return "None";
}


int main() {


    return 0;
}
