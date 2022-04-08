//
// Created by mrusb on 4/8/2022.
//

#include <iostream>
#include <string>
#include <time.h>
#include <iomanip>
#include <windows.h>
#include <vector>


using namespace std;


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
    static const int k = 10;
    unsigned int id;
    string date = "2022-";
    string fio;
    string number;
    int currentcountofproducts = 0;
    int listofproducts[k][2];
};

struct SuperMarket {

    int countofproducts = 0;
    int countoforders = 0;
    int maxcountofproducts = 0;
    int maxcountoforders = 0;

    vector<Product> products;
    vector<Order> orders;

    void CreateListOfProcucts();

    void CreateListOfOrders();

    void PrintProducts();

    void PrintOrders();

    void AddOrder();

    void DelOrder(int id);

    bool AddProduct(int numberoforder, int idproduct, int count);

    unsigned int CalculatingBill(int id);

    SuperMarket(int maxcountofproduct, int maxcountoforder);

};

SuperMarket::SuperMarket(int maxcountofproducts, int maxcountoforders) {
    this->maxcountofproducts = maxcountofproducts;
    this->maxcountoforders = maxcountoforders;

    products.resize(maxcountofproducts);
    orders.resize(maxcountoforders);
}

bool SuperMarket::AddProduct(int numberoforder, int idproduct, int count) {
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

    while (i < countoforders) {
        if (orders[i].currentcountofproducts == 0) {
            auto iter = orders.cbegin();
            orders.erase(iter + i);
            countoforders--;
        }
        else i++;
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
    bool flag = false;
    for (int i = 0; i < countoforders; ++i) {
        if (orders[i].id == id) {
            flag = true;
            for (int i = 0; i < orders[id].currentcountofproducts; i++) {
                products[orders[id].listofproducts[i][0]].count += orders[id].listofproducts[i][1];
            }

            auto iter = orders.cbegin();
            orders.erase(iter + id);

            countoforders--;
        }

    }
    if (!flag) cout << "This id not in orders!" << endl;
}

unsigned int SuperMarket::CalculatingBill(int id) {
    unsigned int sum = 0;
    for (int i = 0; i < orders[id].currentcountofproducts; i++) {
        sum += products[orders[id].listofproducts[i][0]].price * orders[id].listofproducts[i][1];
    }
    return sum;
}

void SuperMarket::PrintProducts() {
    string cherta = "____________________|____________________|____________________|____________________|";
    cout << "                                  Table of product                                 \n";
    cout << "____________________________________________________________________________________\n";
    cout << left << setw(20) << "Id Product";
    cout << "|";
    cout << left << setw(20) << "Name product";
    cout << "|";
    cout << left << setw(20) << "Count product";
    cout << "|";
    cout << left << setw(20) << "Price product";
    cout << "|";
    cout << endl;
    cout << cherta << endl;
    for (int i = 0; i < countofproducts; i++) {
        cout << left << setw(20) << products[i].id;
        cout << "|";
        cout << left << setw(20) << products[i].name;
        cout << "|";
        cout << left << setw(20) << products[i].count;
        cout << "|";
        cout << left << setw(20) << products[i].price;
        cout << "|";
        cout << endl;
        cout << cherta << endl;
    }

    cout << endl;
    cout << endl;
    cout << endl;
}

void SuperMarket::PrintOrders() {
    string cherta = "____________________|____________________|____________________|____________________|";
    cout << "                                  Table of orders                                  \n";
    cout << "____________________________________________________________________________________\n";
    cout << left << setw(20) << "Id Order";
    cout << "|";
    cout << left << setw(20) << "Date order";
    cout << "|";
    cout << left << setw(20) << "Fio order";
    cout << "|";
    cout << left << setw(20) << "Number order";
    cout << "|";
    cout << endl;
    cout << cherta << endl;
    for (int i = 0; i < countoforders; i++) {
        cout << left << setw(20) << orders[i].id;
        cout << "|";
        cout << left << setw(20) << orders[i].date;
        cout << "|";
        cout << left << setw(20) << orders[i].fio;
        cout << "|";
        cout << left << setw(20) << orders[i].number;
        cout << "|";
        cout << endl;
        cout << cherta << endl;
    }

    cout << endl;
    cout << endl;
    cout << endl;

    for (int i = 0; i < countoforders; ++i) {
        cout << "Table of product in orders person with id " << orders[i].id << "      \n";
        cout << "__________________________________________\n";
        cout << left << setw(20) << "Id Product";
        cout << "|";
        cout << left << setw(20) << "Count product";
        cout << "|";
        cout << endl;
        cout << "____________________|____________________|" << endl;
        for (int j = 0; j < orders[i].currentcountofproducts; j++) {
            cout << left << setw(20) << Products[orders[i].listofproducts[j][0]];
            cout << "|";
            cout << left << setw(20) << orders[i].listofproducts[j][1];
            cout << "|";
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

    int n, k, x;


    cout << "Enter max count of product > 0 and < 7" << endl;
    cin >> n;

    cout << "Enter max count of orders > 0 and < 5" << endl;
    cin >> k;

    SuperMarket superMarket(n, k);

    superMarket.CreateListOfProcucts();
    superMarket.CreateListOfOrders();

    superMarket.PrintProducts();
    superMarket.PrintOrders();

    cout << "Enter id order what you want to delete" << endl;
    cin >> x;

    superMarket.DelOrder(x);

    superMarket.PrintOrders();

}