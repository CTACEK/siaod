//
// Created by mrusb on 4/1/2022.
//

#include <iostream>
#include <string>
#include <time.h>
#include <iomanip>
#include <windows.h>


using namespace std;
const int N = 100;
const int maxcountofproducts = 6;
const int maxcountoforders = 4;
int countofproducts = 0;
int countoforders = 0;

string Products[6] = {"Fish", "Meat", "Egg", "Bread", "Cola", "Juice"};
string names[4] = {"Ryan Brown", "Davis Ostin", "Mark Mandel", "John Jobs"};
string numbers[4] = {"+7(936)209-93-10", "+7(981)942-26-08", "+7(941)802-26-23", "+7(970)767-98-51"};


struct Product {
    string name;
    unsigned int id;
    unsigned int count;
    unsigned int price;
};

struct Order {
    unsigned int id;
    string date = "2022-";
    string fio;
    string number;
    int currentcountofproducts = 0;
    int listofproducts[N][2];
};

struct SuperMarket {


    Product products[maxcountofproducts];
    Order orders[maxcountoforders];

    void CreateListOfProcucts();

    void CreateListOfOrders();

    void Print();

    void AddOrder();

    void DelOrder(int id);

    boolean AddProduct(int numberoforder, int idproduct, int count);

    unsigned int CalculatingBill(int id);

};

boolean SuperMarket::AddProduct(int numberoforder, int idproduct, int count) {
    if (products[idproduct].count >= count && idproduct >= 0 && idproduct < 6) {
        orders[numberoforder].listofproducts[orders[numberoforder].currentcountofproducts][0] = idproduct;
        orders[numberoforder].listofproducts[orders[numberoforder].currentcountofproducts][1] = count;
        orders[numberoforder].currentcountofproducts++;
        products[idproduct].count -= count;
        return true;
    }
    return false;
}

void SuperMarket::CreateListOfProcucts() {
    while (countofproducts < maxcountofproducts) {
        products[countofproducts].name = Products[countofproducts];
        products[countofproducts].id = countofproducts;
        products[countofproducts].count = rand() % 10 + 1;
        products[countofproducts].price = rand() % 150 + 50;
        countofproducts++;
    }
}

void SuperMarket::CreateListOfOrders() {
    while (countoforders < maxcountoforders) {
        orders[countoforders].id = countoforders;
        orders[countoforders].date += to_string(rand() % 12 + 1) += "-" + to_string(rand() % 27 + 1);
        orders[countoforders].fio = names[countoforders];
        orders[countoforders].number = numbers[countoforders];
        while (AddProduct(countoforders, rand() % maxcountofproducts + 1, rand() % 9 + 1));
        countoforders++;
    }
    int i = 0;

    while (i < countoforders){
        if(orders[i].currentcountofproducts == 0){
            DelOrder(orders[i].id);
            i--;
        }
        i++;
    }
}

void SuperMarket::AddOrder() {
    int id;
    string date, fio, number;
    cout << "Enter id, date, fio and contact number:" << endl;
    cin >> id >> date >> fio >> number;
    orders[countoforders].id = id;
    orders[countoforders].date = date;
    orders[countoforders].fio = fio;
    orders[countoforders].number = number;
    cout << "Enter id and count of products:\nIf you entered all wishes product enter '-1'." << endl;
    int idproduct, countproduct;
    while (true) {
        cin >> idproduct;
        if (idproduct == -1) break;
        cin >> countproduct;
        if (AddProduct(id, idproduct, countproduct)) { cout << "Successfully!"; }
        else { cout << "Not id or count of product"; }
    }
    cin >> id >> date >> fio >> number;
    countoforders++;
}

void SuperMarket::DelOrder(int id) {

    for (int i = 0; i < orders[id].currentcountofproducts; i++) {
        products[orders[id].listofproducts[i][0]].count += orders[id].listofproducts[i][1];
    }
    orders[id].currentcountofproducts = 0;
    for (int i = id; i < countoforders - 1; ++i) {
        orders[i] = orders[i + 1];
    }
    countoforders--;

}

unsigned int SuperMarket::CalculatingBill(int id) {
    unsigned int sum = 0;
    if (orders[id].id != -1) {
        for (int i = 0; i < orders[id].currentcountofproducts; i++) {
            sum += products[orders[id].listofproducts[i][0]].price * orders[id].listofproducts[i][1];
//            cout << products[orders[id].listofproducts[i][0]].price << endl;
//            cout << orders[id].listofproducts[i][1] << endl;
        }
    } else cout << "Order with this id was deleted :c" << endl;
    return sum;
}

void SuperMarket::Print() {
    string cherta = "____________________|____________________|____________________|____________________|";
    cout << "                                  Table of product                                 \n";
    cout << "____________________________________________________________________________________\n";
    cout << left << setw(20) << "Id Product";cout << "|";
    cout << left << setw(20) << "Name product";cout << "|";
    cout << left << setw(20) << "Count product";cout << "|";
    cout << left << setw(20) << "Price product";cout << "|";
    cout << endl;
    cout << cherta << endl;
    for (int i = 0; i < countofproducts; i++) {
        cout << left << setw(20) << products[i].id;cout << "|";
        cout << left << setw(20) << products[i].name;cout << "|";
        cout << left << setw(20) << products[i].count;cout << "|";
        cout << left << setw(20) << products[i].price;cout << "|";
        cout << endl;
        cout << cherta << endl;
    }

    cout << endl;
    cout << endl;
    cout << endl;


    cout << "                                  Table of orders                                  \n";
    cout << "____________________________________________________________________________________\n";
    cout << left << setw(20) << "Id Order";cout << "|";
    cout << left << setw(20) << "Date order";cout << "|";
    cout << left << setw(20) << "Fio order";cout << "|";
    cout << left << setw(20) << "Number order";cout << "|";
    cout << endl;
    cout << cherta << endl;
    for (int i = 0; i < countoforders; i++) {
        cout << left << setw(20) << orders[i].id;cout << "|";
        cout << left << setw(20) << orders[i].date;cout << "|";
        cout << left << setw(20) << orders[i].fio;cout << "|";
        cout << left << setw(20) << orders[i].number;cout << "|";
        cout << endl;
        cout << cherta << endl;
    }

    cout << endl;
    cout << endl;
    cout << endl;

    for (int i = 0; i < countoforders; ++i) {
        cout << "Table of product in orders person with id " << orders[i].id << "      \n";
        cout << "__________________________________________\n";
        cout << left << setw(20) << "Id Product";cout << "|";
        cout << left << setw(20) << "Count product";cout << "|";
        cout << endl;
        cout << "____________________|____________________|" << endl;
        for (int j = 0; j < orders[i].currentcountofproducts; j++) {
            cout << left << setw(20) << Products[orders[i].listofproducts[j][0]];cout << "|";
            cout << left << setw(20) << orders[i].listofproducts[j][1];cout << "|";
            cout << endl;
            cout << "____________________|____________________|" << endl;
        }
        cout << "Current bill is " << CalculatingBill(i) << " $" << endl;
        cout << endl;
    }
}


int main() {
    setlocale(LC_ALL, "RUS");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(time(0));

    SuperMarket superMarket;
    superMarket.CreateListOfProcucts();
    superMarket.CreateListOfOrders();

    superMarket.Print();

}