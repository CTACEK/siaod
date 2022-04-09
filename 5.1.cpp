//
// Created by mrusb on 4/8/2022.
//
#include <iostream>
#include <string>

using namespace std;


struct Node {
    string data;
    Node *next = nullptr;
};

Node *add_node(Node *root, string data) {
    Node *temp = new Node;
    temp->data = data;
    temp->next = root;
    return temp;
}

Node *create_list() {
    Node *list = nullptr;
    string temp;
    while (true) {
        cin >> temp;
        if (temp[temp.size()-1] == ']') {
            list = add_node(list, temp);
            break;
        }
        list = add_node(list, temp);
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

int count_line_text(Node *root) {
    Node *node = root;
    int k = 0;
    while (node) {
        if (node->data == "\\n") k++;
        node = node->next;
    }
    return k;
}

void rearranging_words(Node *root) {
    Node *node = root;
    while (node->next) {
        if (node->data == "languages" && node->next->data == "programming") {
            string temp = node->data;
            node->data = node->next->data;
            node->next->data = temp;
        }
        node = node->next;
    }
}

void delete_paragraph_character(Node *root){
    Node *node = root;
    while (node) {
        if (node->data[node->data.size()-1] == ']') {node->data = node->data.substr(0,node->data.size()-1);}
        node = node->next;
    }
}


//programming languages have become very popular nowadays. \n It is important for a programmer to know at least a few languages for normal operation.]


int main() {

    Node* list = create_list();

    print_list(list);

    cout << "Count of text lines: "<< count_line_text(list) << endl;
    rearranging_words(list);

    cout << endl;

    print_list(list);

    cout << endl;

    delete_paragraph_character(list);

    print_list(list);

    return 0;
}
