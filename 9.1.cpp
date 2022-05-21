//
// Created by CTACEK on 5/16/2022.
//
#include <iostream>
#include <iomanip>
#include <string>


using namespace std;

string names[4] = {"Ryan Brown", "Davis Ostin", "Mark Mandel", "John Jobs"};
string numbers[4] = {"+7(936)209-93-10", "+7(981)942-26-08", "+7(941)802-26-23", "+7(970)767-98-51"};

struct User {
    string number;
    string address;
};

struct PhoneBook {
    int count_of_users = 0;
    int max_count_of_users = 4;
    User Users[4];

    void add_user(User);

    void print_phonebook();

    void create_randomtable();

    string find_user(string number);

    string find_user_barrier(string number);

};


void PhoneBook::print_phonebook() {
    cout << "Table of users of phonebook" << "      \n";
    cout << "______________________________________________\n";
    cout << left << setw(22) << "Number of user[keys]";
    cout << "|";
    cout << left << setw(22) << "Data of user[values]";
    cout << "|" << endl;
    cout << "______________________|______________________|" << endl;
//    cout << Users[0].number << endl;
    for (User user: Users) {
        cout << left << setw(22) << user.number;
        cout << "|";
        cout << left << setw(22) << user.address;
        cout << "|" << endl;
        cout << "______________________|______________________|" << endl;
    }
    cout << endl;
}

void PhoneBook::create_randomtable() {
    for (int i = 0; i < 4; i++) {
        Users[i].number = numbers[count_of_users];
        Users[i].address = names[count_of_users];
        count_of_users++;
    }
}

string PhoneBook::find_user(string number) {
    for (User user: Users) if (user.number == number) return user.address;
    return "None";
}

string PhoneBook::find_user_barrier(string number) {
    int size = count_of_users;
    if (size != 0) {
        string last = Users[size - 1].address;
        Users[size - 1].number = number;
        int i = 0;
        for (i = 0; Users[i].number != number; ++i)
            Users[size - 1].number = last;
        if (i != (size - 1) || number == last) return Users[i].address;
    }
    return "None";
}


int main() {
    PhoneBook phoneBook;
    phoneBook.create_randomtable();
    phoneBook.print_phonebook();
    cout << "Finding user with linear finding" << endl;
    cout << phoneBook.find_user("+7(941)802-26-23") << endl;
    cout << endl;
    cout << "Finding user with barrier finding" << endl;
    cout << phoneBook.find_user_barrier("+7(941)802-26-23") << endl;
    return 0;
}
