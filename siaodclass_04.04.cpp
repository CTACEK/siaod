//
// Created by CTACEK on 4/4/2022.
//
//узлы - ячейка памяти.
//ptr1 = new node
//ptr1 первый узелочек, (значение, поле ключа, третье поле)

//ptr1 =
//(7 * 0)
//
//ptr2 =
//(2 A 0)
//
//ptr3 =
//(8 B 0)

//L
//(ptr2 ptr1 ptr3) // по возрастанию типо
//
//q = L; // для того чтобы удалить q
//L = L->next;
//delete q;

#include <iostream>
using namespace std;
struct node {
    int key;
    char data;
    node* next = NULL;
};

void outlist(node* L) { // вывод списка, проход по списку до конца
    node* q = L;
    while (q != NULL) {
        cout << q->key << " " << q->data << endl;
        q = q->next;
    }
}

void dellist(node* &L) { // если без & то L отстанется неизменным
    node* q;
    while (L) { // можно написать L != NULL, но можно написать просто L
        q = L;
        L = L->next;
        delete q;
    }
}

int main() {
    node* L = NULL;
    node* ptr1, * ptr2, * ptr3;
    ptr1 = new node;
    ptr1->key = 7;
    ptr1->data = '*';
    //cout << ptr1 << endl;
    ptr2 = new node;
    ptr2->key = 2;
    ptr2->data = 'A';
    //cout << ptr2 << endl;
    ptr3 = new node;
    ptr3->key = 8;
    ptr3->data = 'B';
    //cout << ptr3 << endl;
    L = ptr2;
    ptr2->next = ptr1;
    ptr1->next = ptr3;

    //cout << L;
    outlist(L);
    cout << "Hello world!";
}

