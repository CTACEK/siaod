//
// Created by CTACEK on 4/16/2022.
//

//Дан линейный однонаправленный список.
// Реализовать функцию, реализующую удаление узла из списка по алгоритму клавиши BackSpace.
#include <iostream>

using namespace std;


struct Node {
    int data = 0;
    Node *next = nullptr;
};

void add_node(Node *&root, int data) {
    Node *temp = new Node;
    temp->data = data;
    if (!root){
        root = temp;
    }
    else {
        Node *node = root;
        while (node->next) {
            node = node->next;
        }
        node->next = temp;
    }
}

Node *create_list(int n) {
    Node *list = nullptr;
    int temp;
    for (int _ = 0; _ < n; _++) {
        cin >> temp;
        add_node(list, temp);
    }
    return list;
}

void print_list(Node *root) {
    Node *node = root;
    while (node) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}


void backspace(Node *&root, int index) {
    if (index == 0) {
        Node *temp = root;
        root = root->next;
        free(temp);
    } else if (index == 1) {
        Node *temp = root->next;
        root->next = root->next->next;
        free(temp);
    } else { backspace(root->next, index - 1); }
}

int main() {
    Node *list;
    int index, n;

    cout << "Enter count of elements of list:" << endl;
    cin >> n;

    cout << "Enter elements\n";
    list = create_list(n);

    cout << "Origin list:" << endl;
    print_list(list);

    cout << "Enter index that you want to delete:" << endl;

    cin >> index;

    if (index >= 0 && index < n) backspace(list, index);

    cout << "List without " << index << endl;
    print_list(list);

    return 0;
}