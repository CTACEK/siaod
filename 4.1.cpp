//
// Created by mrusb on 4/1/2022.
//

#include <iostream>
#include <string>
#include <time.h>
#include <iomanip>
#include <windows.h>
#include <vector>


using namespace std;
const int N = 100;
const int maxcountofproducts = 6;
const int maxcountoforders = 4;
int countofproducts = 0;
int countoforders = 0;

string Products[6] = {"Fish", "Meat", "Egg", "Bread", "Cola", "Juice"};
string names[4] = {"Ryan Brown", "Davis Ostin", "Mark Mandel", "John Jobs"};
string numbers[4] = {"+7(536)209-93-10", "+7(781)942-26-08", "+7(741)802-26-23", "+7(670)767-98-51"};


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
    int listofproducts[maxcountofproducts][2];
};

struct SuperMarket {


    Product products[maxcountofproducts];
    Order orders[maxcountoforders];

    void CreateListOfProcucts();

    void CreateListOfOrders();

    void AddOrder();

    void DelOrder();

    void Print();

    boolean AddProduct(int numberoforder, int idproduct, int count);

    void CalculatingBill();
};

boolean SuperMarket::AddProduct(int numberoforder, int idproduct, int count) {
    if (products[idproduct].count > 0) {
        orders[numberoforder].listofproducts[idproduct][0] = idproduct;
        orders[numberoforder].listofproducts[idproduct][1] = count;
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
        while (!AddProduct(countoforders, rand() % maxcountofproducts, rand() % 10));
        countoforders++;
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
//    int n = 0;
//    while (n < countoforders) {
//        cout << superMarket.orders[n].date << endl;
//        n++;
//    }

}
