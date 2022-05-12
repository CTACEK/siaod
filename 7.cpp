//
// Created by CTACEK on 4/18/2022.
//
#include <iostream>

using namespace std;

template<typename Temp>
struct Node {
    Temp data;
    Node *next = nullptr;
};

template<typename T>
struct Stack {
    Node<T> *head = nullptr;
    void push(T data);
    T pop();
    T top();
};

template<typename T>
void Stack<T>::push(T data) {
    Node<T> *temp = new Node<T>;
    temp->data = data;
    temp->next = head;
    head = temp;
}

template<typename T>
T Stack<T>::pop() {
    Node<T> *temp = head;
    head = head->next;
    T temp_value = temp->data;
    free(temp);
    return temp_value;
}

template<typename T>
T Stack<T>::top() {
    return head->data;
}


int compare(char a, char b) {
    string first_class = "+-";
    string second_class = "*/";
    if (first_class.find(a) != string::npos) {
        if (first_class.find(b) != string::npos) return 0;
        else return -1;
    } else {
        if (second_class.find(b) != string::npos) return 0;
        else return 1;
    }
}


bool is_operation(char a) {
    return a == '+' || a == '-' || a == '*' || a == '/';
}


bool is_bracket(char a) {
    return a == '(' || a == ')';
}

int operation(char i, int a, int b) {
    switch (i) {
        case '+':return b + a;
        case '-':return b - a;
        case '*':return b * a;
        case '/':return b / a;
    }
}


void make_one_operation(Stack<char> &operations, Stack<int> &letters) {
    int operand2 = letters.pop();
    int operand1 = letters.pop();
    int result = operation(operations.pop(), operand2, operand1);
    letters.push(result);
}


void make_all_operations(Stack<char> &operations, Stack<int> &letters) {
    while (operations.head != nullptr) make_one_operation(operations, letters);
}


void make_brackets_operations(Stack<char> &operations, Stack<int> &letters) {
    while (operations.top() != '(') make_one_operation(operations, letters);
}

int preob(char temp) {
    return temp - '0';
}

int inf_to_result(string s) {
    Stack<char> operations;
    Stack<int> result;
    for (char k: s) {
        if (is_operation(k)) {
            if (operations.head != nullptr && !is_bracket(operations.top()) && compare(k, operations.top()) <= 0) {
                make_one_operation(operations, result);
            }
            operations.push(k);
        } else if (is_bracket(k)) {
            if (k == '(') operations.push(k);
            else {
                make_brackets_operations(operations, result);
                operations.pop();
            }
        } else result.push(preob(k));
    }
    make_all_operations(operations, result);
    return result.top();
}


int main() {
    string input;
    cout << "Enter your expression in infix form:\n";
    cin >> input;
    cout << "Answer: " <<inf_to_result(input) << endl;
}

